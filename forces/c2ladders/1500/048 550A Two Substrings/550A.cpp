#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	int AB[2] = {-1,-1};
	int BA[2] = {-1,-1};
	for (int i = 0; i < str.size()-1; ++i) {
		if (str[i] == 'A' && str[i+1] == 'B') {
			AB[0] = i+1;
			break;
		}
	}
	if (AB[0] == -1) {
		printf("NO\n");
		return 0;
	}
	for (int i = str.size()-1; i >= 1; --i) {
		if (str[i] == 'B' && str[i-1] == 'A') {
			AB[1] = i-1;
			break;
		}
	}
	for (int i = 0; i < str.size()-1; ++i) {
		if (str[i] == 'B' && str[i+1] == 'A') {
			BA[0] = i+1;
			break;
		}
	}
	if (BA[0] == -1) {
		printf("NO\n");
		return 0;
	}
	for (int i = str.size()-1; i >= 1; --i) {
		if (str[i] == 'A' && str[i-1] == 'B') {
			BA[1] = i-1;
			break;
		}
	}
	// printf("%d %d %d %d\n",AB[0],AB[1],BA[0],BA[1]);
	if (AB[0] >= BA[1] && BA[0] >= AB[1]) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
	return 0;
}