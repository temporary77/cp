#include <bits/stdc++.h>
using namespace std;

int sieve[20001];
int arr[20001];
vector<int> cnt[20001];
int ans = INT_MIN;

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (long long i = 3; i <= 20000; ++i) {
		if (!sieve[i]) {
			for (long long j = i*i; j <= 20000; j += i) {
				sieve[j] = i;
			}
		}
	}
	for (int i = n/3; i >= 1; --i) {
		if (n%i)continue;
		int s = n/i;
		if (!sieve[s]) {
			for (int j = 0; j < i; ++j) {
				int cur = 0;
				for (int k = j; k < n; k += i) {
					cur += arr[k];
				}
				cnt[i].push_back(cur);
				ans = max(ans,cur);
			}
		} else {
			int b = n/(s/sieve[s]);
			for (int j = 0; j < i; ++j) {
				int cur = 0;
				for (int k = j; k < b; k += i) {
					cur += cnt[b][k];
				}
				cnt[i].push_back(cur);
				ans = max(ans,cur);
			}
		}
	}
	printf("%d",ans);
	return 0;
}