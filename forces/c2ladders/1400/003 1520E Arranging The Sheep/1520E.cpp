#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int idx = vctr.size();
		int n;
		scanf("%d",&n);
		string str;
		cin >> str;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (str[i] == '*') {
				vctr.push_back(i);
				++cnt;
			}
		}
		long long ans = 0;
		int m = cnt/2;
		// printf("%d <\n",vctr[idx+m]);
		for (int i = 0; i < cnt; ++i) {
			ans += abs(vctr[idx+m]-vctr[idx+i]);//-abs(m-i);
		}
		// printf("%lld <<\n",ans);
		ans -= (long long)m*(m+1)/2+(long long)(cnt-m-1)*(cnt-m)/2;
		printf("%lld\n",ans);
	}
	return 0;
}