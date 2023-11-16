#include <bits/stdc++.h>
using namespace std;

stack<int> stck;
queue<int> que;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		que.push(0);
		for (int i = 1; i <= sqrt(n); ++i) {
			que.push(i);
			if (i != n/i)stck.push(n/i);
		}
		printf("%d\n",que.size()+stck.size());
		for (;!que.empty();) {
			printf("%d ",que.front());
			que.pop();
		}
		for (;!stck.empty();) {
			printf("%d ",stck.top());
			stck.pop();
		}
		printf("\n");
	}
	return 0;
}