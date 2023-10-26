#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	string str1, str2;
	cin >> str1 >> str2;
	int val1 = 0, val2 = 0;
	int n = str1.size();
	for (int i = 0; i < n; ++i) {
		str1[i] = tolower(str1[i]);
		str2[i] = tolower(str2[i]);
	}
	if (str1 < str2) {
		printf("-1");
	} else if (str1 == str2) {
		printf("0");
	} else {
		printf("1");
	}

	return 0;
}