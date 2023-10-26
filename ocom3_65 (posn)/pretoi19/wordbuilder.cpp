#include <bits/stdc++.h>
using namespace std;

char arr[200001];
vector<int> graph[200001];
map<char,int> mp;
queue<int> que;
bool visited[200001];

int main() {
	cin.tie(nullptr);
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		arr[i] = str[i]; 
	}
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		--a, --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cin >> str;
	for (int i = 0; i < k; ++i) {
		++mp[str[i]];
	}
	que.push(0);
	int d = 0;
	long long ans = 0;
	visited[0] = 1;
	for (;!que.empty();) {
		int t = que.size();
		for (int i = 0; i < t; ++i) {
			b = que.front();
			que.pop();
			if (mp[arr[b]] > 0) {
				--mp[arr[b]];
				ans += 2*d;
				--k;
			}
			for (auto it : graph[b]) {
				if (visited[it] == 0) {
					que.push(it);
					visited[it] = 1;
				}
			}
		}
		++d;
	}
	if (k > 0) {
		printf("-1");
		return 0;
	}
	printf("%lld",ans);
	return 0;
}