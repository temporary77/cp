#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;
long long n, k;
int arr[200002];

int main() {
	scanf("%lld%lld",&n,&k);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		if (i <= k)++mp[arr[i]];
	}
	long long cnt = (2*n-k+1)*k/2;
	int r = k;
	for (int i = 0; i < n-k; ++i) {
		//printf("%d %lld\n",i,cnt);
		/*for (auto it : mp) {
			printf("[%d]=%d,",it);
		}
		printf("\n");*/
		//printf("\n%d size\n",mp.size());
		if (mp.size() <= k) {
			//printf("%d %d\n",i,r);
			++r;
			++mp[arr[r]];
			for (;mp.size() <= k;) {
				++r;
				++mp[arr[r]];
			}
			mp.erase(arr[r]);
			--r;
			//printf(">>>> %d %d %d %d\n",r,i,k,r-i+k+1);
			cnt += r-i-k+1;
		} else {
			++r;
			++mp[arr[r]];
		}
		--mp[arr[i]];
		if (mp[arr[i]] == 0)mp.erase(arr[i]);
	}
	printf("%lld",cnt);
	return 0;
}