#include <bits/stdc++.h>
using namespace std;

map<int,vector<pair<int,int>>> graph;

int main() {
	//freopen("test_input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	//int arr[n][n];
	int w;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d",&w);
			graph[i].push_back({j,w});
			//arr[i][j] = w;
		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] != arr[j][i]) {
				if (arr[i][j] == 0 || arr[j][i] == 0) {
					cout << 1/0;
				}
			}
		}
	}*/
	bool visited[n] = {0};
	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
	long long ans = 0;
	for (auto it : graph[0]) {
		pq.push({it.second,0,it.first});
	}
	visited[0] = 1;
	for (int i = 1; i < n;) {
		tuple<int,int,int> tpl = pq.top();
		//printf("tuple %d %d %d\n",get<0>(tpl),get<1>(tpl),get<2>(tpl));
		if (visited[get<2>(tpl)] == 1) {// && visited[get<1>(tpl)] == 1) {
			pq.pop();
			continue;
		}
		//printf("chosen %d %d %d\n",get<0>(tpl),get<1>(tpl),get<2>(tpl));
		for (auto it : graph[get<2>(tpl)]) {
			if (visited[it.first] == 0)pq.push({it.second,get<2>(tpl),it.first});
		}
		ans += get<0>(tpl);
		pq.pop();
		visited[get<2>(tpl)] = 1;
		++i;
	}
	printf("%lld",ans);

	return 0;
}