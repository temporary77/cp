#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		string str;
		cin >> str;
		string cur = "";
		string ans = str;
		int k = 1;
		cur.push_back(str[0]);
		for (int i = 2; i <= n; ++i) {
			string fin = cur;
			if ((n-i+1)&1) {
				reverse(fin.begin(),fin.end());
			}
			fin = str.substr(i-1) + fin;
			if (fin < ans) {
				ans = fin;
				k = i;
			}
			cur.push_back(str[i-1]);
		}
		cout << ans << '\n';
		printf("%d\n",k);
	}
	return 0;
}