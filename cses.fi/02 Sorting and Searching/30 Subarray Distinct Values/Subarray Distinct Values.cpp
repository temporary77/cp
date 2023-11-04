#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;
int n, k;
int arr[200002];

int main() {
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		if (i < k)++mp[arr[i]];
	}
	long long cnt = 0;//(2*n-k+1)*k/2;
	int r = k-1;
	for (int i = 0; i < n; ++i) {
		//printf("%d %d\n",i,cnt);
		/*for (auto it : mp) {
			printf("[%d]=%d,",it);
		}
		printf("\n");*/
		//printf("\n%d size\n",mp.size());
		//printf("%d %d\n",i,r);
		for (;mp.size() <= k;) {
			if (r == n)break;
			++r;
			if (r == n)break;
			++mp[arr[r]];
		}
		// mp.erase(arr[r]);
		// --r;
		// printf(">>>> %d %d %d %d\n",r,i,k,r-i);
		cnt += r-i;
		--mp[arr[i]];
		if (mp[arr[i]] == 0)mp.erase(arr[i]);
	}
	printf("%lld",cnt);
	return 0;
}