#include <bits/stdc++.h>
using namespace std;

map<char,int> mp, mp2;

int main() {
	cin.tie(nullptr);
	int n, m;
	scanf("%d%d",&n,&m);
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 0; i < m; ++i) {
		++mp2[str2[i]];
	}
	int a = 0;
	long long cnt = 0;
	for (int i = 0; i < n; ++i) {
		++mp[str1[i]];
		for (;mp[str1[i]] > mp2[str1[i]];) {
			--mp[str1[a]];
			++a;
		}
		cnt += i-a+1;
		//printf("%lld\n",cnt);
	}
	printf("%lld",cnt);
	return 0;
}