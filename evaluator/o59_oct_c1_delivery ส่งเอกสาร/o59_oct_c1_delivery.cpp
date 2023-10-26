#include <bits/stdc++.h>
using namespace std;

int k;

int dist(int a, int b) {
	bool ca = a < 1 << k;
	bool cb = b < 1 << k;
	if (ca^cb)return 1e9;
	if (!ca)a -= 1 << k;
	if (!cb)b -= 1 << k;
	int cnt = 0;
	for (;;) {
		if (a == b)break;
		if (a < b) {
			b /= 2;
		} else if (a > b) {
			a /= 2;
		}
		++cnt;
	}
	return cnt;
}

vector<int> shortcut;
unordered_map<int,int> idx;
unordered_map<int,vector<int>> graph;
int graph2[10][10];

int main() {
	int m, q;
	scanf("%d%d%d",&k,&m,&q);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		if (find(shortcut.begin(),shortcut.end(),a) == shortcut.end())shortcut.push_back(a);
		if (find(shortcut.begin(),shortcut.end(),b) == shortcut.end())shortcut.push_back(b);
		graph[a].push_back(b);
	}
	int t = 0;
	for (auto it : shortcut) {
		idx[it] = t;
		++t;
	}
	for (int i = 0; i < shortcut.size(); ++i) {
		for (int j = i+1; j < shortcut.size(); ++j) {
			graph2[i][j] = dist(shortcut[i],shortcut[j]);
			graph2[j][i] = dist(shortcut[j],shortcut[i]);
		}
	}
	for (auto it : shortcut) {
		for (auto it2 : graph[it]) {
			graph2[idx[it]][idx[it2]] = 1;
			graph2[idx[it2]][idx[it]] = 1;
		}
	}
	for (int l = 0; l < shortcut.size(); ++l) {
		for (int i = 0; i < shortcut.size(); ++i) {
			for (int j = 0; j < shortcut.size(); ++j) {
				if (graph2[i][l] == 1e9 || graph2[l][j] == 1e9)continue;
				graph2[i][j] = min(graph2[i][j],graph2[i][l]+graph2[l][j]);
			}
		}
	}
	for (int i = 0; i < q; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		int ans = dist(a,b);
		for (int j = 0; j < shortcut.size(); ++j) {
			for (int l = 0; l < shortcut.size(); ++l) {
				if (j == l)continue;
				ans = min(ans,dist(a,shortcut[j])+graph2[j][l]+dist(shortcut[l],b));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}