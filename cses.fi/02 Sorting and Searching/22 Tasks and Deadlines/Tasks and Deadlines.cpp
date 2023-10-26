#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[200002];
int n;
long long sum = 0;
long long cur = 0;

int main() {
	scanf("%d",&n);
	int a, b;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&arr[i].first,&arr[i].second);
	}
	sort(arr,arr+n);
	for (int i = 0; i < n; ++i) {
		//printf("%d\n",arr[i].first);
		cur += arr[i].first;
		sum += arr[i].second-cur;
		//printf("%d %d %d\n",sum,arr[i].first,cur);
	}
	printf("%lld",sum);
	return 0;
}
/*
5 9
5 10
5 10  4
5 10  8 2

6 10
8 15
5 12
   x  y
5 11 19    +(x-11)+(y-19)
5 13 19 X  +(y-13)+(x-19)
6 11 19
6 14 19 X
8 13 19
8 14 19 X
*/