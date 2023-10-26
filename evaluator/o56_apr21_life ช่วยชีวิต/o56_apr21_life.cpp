#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
vector<int> graph2[100001];
pair<int,int> bridges[300001];
int visited[100001];

int iter = 1;
void dfs1(int node, int pa, int dist) {
	// printf("%d %d %d %d\n",iter,node,pa,dist);
	visited[node] = iter;
	if (dist <= 0)return;
	for (auto it : graph[node]) {
		if (bridges[it].second == pa)continue;
		if (visited[bridges[it].second] == iter)continue;
		dfs1(bridges[it].second,node,dist-1);
	}
	return;
}

bool dfs2(int node, int pa, int dist) {
	// printf("%d %d %d %d\n",iter,node,pa,dist);
	if (visited[node] == iter-1) {
		return 1;
	}
	visited[node] = iter;
	if (dist <= 0)return 0;
	bool check = 0;
	// printf("buh\n");
	for (auto it : graph2[node]) {
		// printf("%d <<<\n",it);
		if (bridges[it].first == pa)continue;
		if (visited[bridges[it].first] == iter)continue;
		check |= dfs2(bridges[it].first,node,dist-1);
		if (check)break;
	}
	return check;
}

int main() {
	int n, m, l, q;
	scanf("%d%d%d%d",&n,&m,&l,&q);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(i);
		graph2[b].push_back(i);
		bridges[i] = {a,b};
	}
	int bnum = m+1;
	for (int qi = 0; qi < q; ++qi) {
		int k;
		scanf("%d",&k);
		if (k == 1) {
			int c, d;
			scanf("%d%d",&c,&d);
			// printf("%d %d <<<<<<<<\n",c,d);
			dfs1(c,-1,l/2);
			++iter;
			printf("%d\n",dfs2(d,-1,l-l/2));
			++iter;
		} else if (k == 2) {
			int c;
			scanf("%d",&c);
			int a, b;
			tie(a,b) = bridges[c];
			if (graph[a][0] == c)graph[a].erase(graph[a].begin());
			else graph[a].erase(graph[a].begin()+1);
			if (graph2[b][0] == c)graph2[b].erase(graph2[b].begin());
			else graph2[b].erase(graph2[b].begin()+1);
		} else if (k == 3) {
			int e, f;
			scanf("%d%d",&e,&f);
			graph[e].push_back(bnum);
			graph2[f].push_back(bnum);
			bridges[bnum] = {e,f};
			++bnum;
		}
	}
	return 0;
}