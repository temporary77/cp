#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vctr[2] = {{{1,1},{3,1}},{{1,3},{2,3},{3,3},{4,3}}};

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	int i1 = 0, i2 = 0;
	for (auto it : str) {
		if (it == '0') {
			printf("%d %d\n",vctr[0][i1]);
			i1 = ++i1%2;
		} else if (it == '1') {
			printf("%d %d\n",vctr[1][i2]);
			i2 = ++i2%4;
		}
	}
	return 0;
}