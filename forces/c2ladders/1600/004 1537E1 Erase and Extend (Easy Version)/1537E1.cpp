#include <bits/stdc++.h>
using namespace std;

set<char> st;

int main() {
	cin.tie(NULL);
	int n, k;  
	scanf("%d%d",&n,&k);
	string str;
	cin >> str;
	string ans(k,'z');
	for (int i = 1; i <= n; ++i) {
		string cur = "";
		for (int j = 0; j < k; ++j) {
			cur.push_back(str[j%i]);
		}
		ans = min(ans,cur);
	}
	cout << ans;
	return 0;
}