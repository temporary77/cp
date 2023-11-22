#include <bits/stdc++.h>
using namespace std;

int cnt1[26];
int cnt2[26];

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str1, str2;
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		cin >> str1 >> str2;
		fill(cnt1,cnt1+26,0);
		fill(cnt2,cnt2+26,0);
		for (auto it : str1)++cnt1[it-'a'];
		for (auto it : str2)++cnt2[it-'a'];
		for (int i = 0; i < 25; ++i) {
			if (cnt1[i] < cnt2[i] || (cnt1[i]-cnt2[i])%k) {
				printf("No\n");
				goto g;
			}
			cnt1[i+1] += cnt1[i]-cnt2[i];
		}
		printf("Yes\n");
		g:;
	}
	return 0;
}