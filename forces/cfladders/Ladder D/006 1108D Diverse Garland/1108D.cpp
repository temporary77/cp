#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int n;
	scanf("%d",&n);
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 1; i < n; ++i) {
		if (str[i] == str[i-1]) {
			++cnt;
			if (str[i-1] == 'R') {
				if (i == n-1) {
					str[i] = 'G';
					break;
				}
				if (str[i+1] == 'B') {
					str[i] = 'G';
				} else {
					str[i] = 'B';
				}
			} else if (str[i-1] == 'G') {
				if (i == n-1) {
					str[i] = 'B';
					break;
				}
				if (str[i+1] == 'R') {
					str[i] = 'B';
				} else {
					str[i] = 'R';
				}				
			} else if (str[i-1] == 'B') {
				if (i == n-1) {
					str[i] = 'R';
					break;
				}
				if (str[i+1] == 'G') {
					str[i] = 'R';
				} else {
					str[i] = 'G';
				}				
			}
		}
	}
	printf("%d\n",cnt);
	cout << str;
	return 0;
}