#include <bits/stdc++.h>
using namespace std;

bool flip[100001];

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	int s = str.size();
	int m;
	scanf("%d",&m);
	int a;
	for (int i = 0; i < m; ++i) {
		scanf("%d",&a);
		if (a > s/2)a = s-a+1;
		flip[a] ^= 1;
	}
	bool cur = 0;
	for (int i = 1; i <= s/2; ++i) {
		cur ^= flip[i];
		if (cur)swap(str[i-1],str[s-i]);
	}
	cout << str;
	return 0;
}