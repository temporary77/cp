#include <bits/stdc++.h>
using namespace std;

queue<int> que;
bool deployed[101];

int main() {
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		int n;
		scanf("%d",&n);
		int cur = 1;
		int k;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&k);
			if (k == cur) {
				printf("%d ",k);
				deployed[cur] = true;
				for (;que.size() > 1;) {
					printf("%d ",que.front());
					deployed[que.front()] = true;
					que.pop();
				}
				for (;;) {
					++cur;
					if (!deployed[cur])break;
				}
				if (que.front() == cur) {
					printf("%d ",que.front());
					deployed[cur] = true;
					que.pop();
					for (;;) {
						++cur;
						if (!deployed[cur])break;
					}
				}
			} else {
				que.push(k);
			}
		}
		printf("\n");
		fill(deployed+1,deployed+n+1,false);
	}
	return 0;
}