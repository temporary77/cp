#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	bool check = false;
	for (int i = 0; i < str.size()-1; ++i) {
		if (!check) {
			if (str[i] == 'A' && str[i+1] == 'B') {
				check = true;
				++i;
			}
		} else {
			if (str[i] == 'B' && str[i+1] == 'A') {
				printf("YES\n");
				return 0;
			}			
		}
	}
	check = false;
	for (int i = 0; i < str.size()-1; ++i) {
		if (!check) {
			if (str[i] == 'B' && str[i+1] == 'A') {
				check = true;
				++i;
			}
		} else {
			if (str[i] == 'A' && str[i+1] == 'B') {
				printf("YES\n");
				return 0;
			}			
		}
	}
	printf("NO\n");
	return 0;
}