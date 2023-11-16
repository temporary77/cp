#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int n;
	scanf("%d",&n);
	string str;
	cin >> str;
	int ans = 0;
	string str2 = "";
	for (int i = 0; i <= n-1; ++i) {
		for (;i < n-1 && str[i] == str[i+1];) {
			++ans;
			++i;
		}
		if (i >= n)break;
		str2.push_back(str[i]);
		++i;
		if (i >= n)break;
		str2.push_back(str[i]);
	}
	if ((n-ans)&1) {
		++ans;
		str2.pop_back();
	}
	printf("%d\n",ans);
	cout << str2;
	return 0;
}