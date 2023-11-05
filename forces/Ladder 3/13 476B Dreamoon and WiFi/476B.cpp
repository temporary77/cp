#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	int cnt = 0;
	for (auto it : str1) {
		if (it == '+') {
			++cnt;
		} else if (it == '-') {
			--cnt;
		}
	}
	int x = 0;
	int cur = 0;
	for (auto it : str2) {
		if (it == '+') {
			++cur;
		} else if (it == '-') {
			--cur;
		} else {
			++x;
		}
	}
	int d = abs(cnt-cur);
	int need = (x-d)/2;
	if (need < 0) {
		printf("0.000000000000");
		return 0;
	}
	double ans = 1;
	for (int i = x-need+1; i <= x; ++i) {
		ans *= i;
	}
	for (int i = 1; i <= need; ++i) {
		ans /= i;
	}
	ans /= pow(2,x);
	printf("%.12f",ans);
	return 0;
}