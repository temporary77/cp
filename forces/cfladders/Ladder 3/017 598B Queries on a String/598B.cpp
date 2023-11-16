#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	int m;
	scanf("%d",&m);
	int l, r, k;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&l,&r,&k);
		rotate(str.begin()+l-1,str.begin()+(r-(k%(r-l+1))),str.begin()+r);
	}
	cout << str;
	return 0;
}