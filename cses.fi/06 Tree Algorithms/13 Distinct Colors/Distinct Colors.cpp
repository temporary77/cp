#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200001];
vector<int> graph[200001];
int hchild[200001];
int start1[200001];
int end1[200001];
int tme[200001];
unordered_map<int,int> mp;
int ans[200001];
int cnt = 0;

int timer = 0;
void eulertour(int node, int pa) {
	start1[node] = timer;
	tme[timer] = node;
	++timer;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		eulertour(it,node);
	}
	end1[node] = timer;
	return;
}

int findhchild(int node, int pa) {
	hchild[node] = -1;
	int max1 = -1;
	int sz = 0;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		int csz = findhchild(it,node);
		sz += csz;
		if (csz > max1) {
			max1 = csz;
			hchild[node] = it;
		}
	}
	// printf("%d %d <<\n",hchild[node],node);
	return sz+1;
}

void sack(int node, int pa, bool keep) {
	for (auto it : graph[node]) {
		if (it == pa || it == hchild[node])continue;
		sack(it,node,0);
	}
	if (hchild[node] != -1) {
		sack(hchild[node],node,1);
	}
	int c = arr[node];
	if (mp.find(c) == mp.end() || mp[c] == 0) {
		++cnt;
	}
	++mp[c];
	for (auto it : graph[node]) {
		if (it == pa || it == hchild[node])continue;
		for (int tt = start1[it]; tt < end1[it]; ++tt) {
			if (mp.find(arr[tme[tt]]) == mp.end() || mp[arr[tme[tt]]] == 0) {
				++cnt;
			}
			++mp[arr[tme[tt]]];	
		}
	}
	ans[node] = cnt;
	if (!keep) {
		for (int tt = start1[node]; tt < end1[node]; ++tt) {
			--mp[arr[tme[tt]]];
			if (mp[arr[tme[tt]]] == 0) {
				--cnt;
				mp.erase(arr[tme[tt]]);
			}
		}
	}
	return;
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	eulertour(1,-1);
	findhchild(1,-1);
	sack(1,-1,1);
	for (int i = 1; i <= n; ++i) {
		printf("%d ",ans[i]);
	}
	return 0;
}