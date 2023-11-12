#include <bits/stdc++.h>
using namespace std;

queue<int> que;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int k = 0;
		int locked[10001] = {0};
		int p;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&p);
			que.push(p);
			locked[p] = 1;
		}
		for (int i = 0; i < n; ++i) {
			int pin = que.front();
			que.pop();
			if (locked[pin] == 2) {
				++k;
				for (;locked[pin];) {
					++pin;
					if (!(pin%10))pin -= 10;
				}
			}
			locked[pin] = 2;
			que.push(pin);
		}
		printf("%d\n",k);
		for (;!que.empty();) {
			printf("%04d\n",que.front());
			que.pop();
		}
	}
	return 0;
}