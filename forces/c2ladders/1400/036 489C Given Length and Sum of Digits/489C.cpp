#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, s;
	scanf("%d%d",&m,&s);
	if (s < 1 || s > 9*m) {
		if (s == 0 && m == 1) {
			printf("0 0\n");
			return 0;
		}
		printf("-1 -1\n");
		return 0;
	}
	int si = s;
	string str1;
	for (;si > 0;) {
		if (si <= 9) {
			if (str1.size() == m-1) {
				str1.push_back(si+'0');
			} else {
				str1.push_back(si-1+'0');
				for (;str1.size() < m-1;) {
					str1.push_back('0');
				}
				str1.push_back('1');
			}
			si = 0;
		} else {
			str1.push_back(min(9,si)+'0');
			si -= 9;
		}
	}
	reverse(str1.begin(),str1.end());
	string str2;
	for (;s > 0;) {
		str2.push_back(min(9,s)+'0');
		s -= min(9,s);
	}
	for (;str2.size() < m;) {
		str2.push_back('0');
	}
	cout << str1 << ' ' << str2 << '\n';
	return 0;
}