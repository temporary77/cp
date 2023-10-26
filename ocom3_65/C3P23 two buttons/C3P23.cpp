#include <bits/stdc++.h>
using namespace std;

unordered_map<int,bool> mp;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	if (n >= m) {
		printf("%d",n-m);
		return 0;
	}
	queue<int> que;
	que.push(n);
	mp[n] = 1;
	int cnt = 0;
	int min1 = INT_MAX;
	for (;!que.empty();) {
		int t = que.size();
		for (int i = 0; i < t; ++i) {
			int x = que.front();
			//printf("%d %d\n",cnt,x);
			que.pop();
			if (mp[2*x] == 0) {
				if (2*x >= m) min1 = min(min1,cnt+2*x-m+1);
				else que.push(2*x);
				mp[2*x] = 1;
			}
			if (x >= 2 && mp[x-1] == 0) {
				que.push(x-1);
				mp[x-1] = 1;
			}
		}
		++cnt;
	}
	printf("%d",min1);
	return 0;
}