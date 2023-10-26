#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int n;
	scanf("%d",&n);
	string str;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		if (str.size() > 10) {
			printf("%c%d%c\n",str[0],str.size()-2,*str.rbegin());
		} else {
			cout << str << '\n';
		}
	}
	return 0;
}