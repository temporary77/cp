#include <bits/stdc++.h>
using namespace std;

stack<int> stck[2];
queue<int> que;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		cin >> str;
		int idx = 0;
		for (auto it : str) {
			int x = it-'0';
			if (stck[x^1].empty()) {
				++idx;
				stck[x].push(idx);
				que.push(idx);
			} else {
				stck[x].push(stck[x^1].top());
				stck[x^1].pop();
				que.push(stck[x].top());
			}
		}
		printf("%d\n",stck[0].size()+stck[1].size());
		for (;!que.empty();) {
			printf("%d ",que.front());
			que.pop();
		}
		printf("\n");
		for (;!stck[0].empty();)stck[0].pop();
		for (;!stck[1].empty();)stck[1].pop();
	}
	return 0;
}