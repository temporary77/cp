#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	reverse(str2.begin(),str2.end());
	if (str1 == str2) {
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}