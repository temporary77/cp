#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int arr[200001];
int brr[200001];
int visited[200001];
queue<pair<int,int>> que;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 1; ti <= t; ++ti) {
		int n;
		scanf("%d",&n);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d",&x);
			if (visited[x] != ti) {
				visited[x] = ti;
				brr[i] = x;
				arr[x] = i;
				++ans;
			} else {
				que.push({i,x});
			}
		}
		int idx = 1;
		for (;!que.empty();) {
			for (;visited[idx] == ti;)++idx;
			if (que.front().f == idx) {
				que.push({arr[que.front().s],que.front().s});
				brr[que.front().f] = que.front().s;
				arr[que.front().s] = que.front().f;
				que.pop();
			} else {
				brr[que.front().f] = idx;
				que.pop();
				++idx;
			}
		}
		printf("%d\n",ans);
		for (int i = 1; i <= n; ++i) {
			printf("%d ",brr[i]);
		}
		printf("\n");
	}
	return 0;
}

/*
1 2 3 4 5 6
3 X 4 2 6 5

2 3
*/

