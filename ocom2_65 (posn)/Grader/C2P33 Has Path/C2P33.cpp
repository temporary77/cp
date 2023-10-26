#include <bits/stdc++.h>
using namespace std;

map<int,set<int>> graph;
int ans;
map<int,int> visited;
set<int> st;

void recursion(int k, int t) {
	if (st.find(k) == st.end())return;
	if (visited[k] == 0)++ans;
	visited[k] = t;
	/*for (auto it : visited) {
		printf("%d ",it.second);
	}
	printf("\n");
	for (auto it : visited) {
		printf("%d ",it.first);
	}
	printf("\n---%d-%d---\n",ans,t);*/
	--t;
	for (auto it : graph[k]) {
		if (visited[it] < t) {
			recursion(it,t);
		}
	}
	return;
}

int main() {
	//freopen("test_input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].insert(b);
		graph[b].insert(a);
		st.insert(a);
		st.insert(b);
	}
	/*for (auto it : st) {
		printf("%d ",it);
	}
	printf("\n");*/
	int k, t;
	for (;;) {
		scanf("%d%d",&k,&t);
		ans = 0;
		if (k == 0 && t == 0)break;	
		recursion(k,t+1);
		printf("%d\n",st.size()-ans);
		visited.clear();
	}
	return 0;
}