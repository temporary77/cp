#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	map<int,int> mp;
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d",&k);
		for (int j = 0; j < k; ++j) {
			int id;
			scanf("%d",&id);
			mp[id] = i;
		}
	}
	queue<int> que1, que2[n];
	for (;;) {
		char c;
		scanf(" %c",&c);
		if (c == 'S')break;
		if (c == 'E') {
			int id;
			scanf("%d",&id);
			int d = mp[id];
			if (que2[d].empty()) {
				que1.push(d);
			}
			que2[d].push(id);
		}
		if (c == 'D') {
			printf("%d\n",que2[que1.front()].front());
			que2[que1.front()].pop();
			if (que2[que1.front()].empty()) {
				que1.pop();
			}
		}
	}
	return 0;
}