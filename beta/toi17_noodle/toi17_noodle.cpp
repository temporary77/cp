#include <bits/stdc++.h>
using namespace std;

long long arr[100001];
priority_queue<int, vector<int>, greater<int>> vctr;

int main() {
	int n, m;
	long long k;
	scanf("%d%d%lld",&n,&m,&k);
	long long l = 1e11, r = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		l = min(l,arr[i]);
		r = max(r,arr[i]);
	}
	l *= k;
	r *= k;
	long long ans = 0;
	for (;;) {
		//printf("%lld %lld\n",l,r);
		if (l > r)break;
		long long mid = (l+r)/2;
		//printf("------- %lld %lld %lld\n",l,r,mid);
		int cur = 0;
		long long cnt = 0;
		for (;!vctr.empty();)vctr.pop();
		for (int i = 0; i <= n; ++i) {
			/*if (i == n) {
				if (cnt >= mid) {
					++cur;
				}
			}*/
			if (i == n)break;
			vctr.push(arr[i]);
			/*printf("%d %d %lld %lld\n",i,cur,cnt,mid);
			for (int j = 0; j < n; ++j) {
				printf("%d ",vctr[j]);
			}
			printf("\n");*/
			cnt += arr[i];
			if (vctr.size() < k) {
				//auto it = upper_bound(vctr.begin()+ix,vctr.begin()+i,arr[i]);
				//printf("%d %d %d\n",it-vctr.begin(),i,i+1);
				//rotate(it,vctr.begin()+i,vctr.begin()+i+1);
				continue;
			}
				//auto it = upper_bound(vctr.begin()+ix,vctr.begin()+i,arr[i]);
				//printf("> %d\n",it-vctr.begin());
				/*if (vctr.begin()+i+1-it <= k) {
					cnt += arr[i]-*(vctr.begin()+i-k);
				}
				rotate(it,vctr.begin()+i,vctr.begin()+i+1);*/
			if (vctr.size() > k) {
				cnt -= vctr.top();
				vctr.pop();
			}
			if (cnt >= mid) {
				++cur;
				cnt = 0; // 5 7 9   8
				for (;!vctr.empty();) {
					//printf("%d ",vctr.top());
					vctr.pop();
				}
				//printf("\n");
			}
		}
		//printf("%d <<<\n",cur);
		if (cur >= m) {
			ans = max(ans,mid);
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}