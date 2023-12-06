#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		cin >> str;
		int x;
		scanf("%d",&x);
		string str2(str.size(),'1');
		for (int i = 0; i < str.size(); ++i) {
			if (str[i]-'0' == 1)continue;
			if (i >= x)str2[i-x] = '0';
			if (i+x < str2.size())str2[i+x] = '0';
		}
		for (int i = 0; i < str2.size(); ++i) {
			if (str[i]-'0' == 0)continue;
			if ((i < x || str2[i-x] == '0') && (i+x >= str2.size() || str2[i+x] == '0')) {
				printf("-1\n");
				goto g;
			}
		}
		cout << str2 << '\n';
		g:;
	}
	return 0;
}