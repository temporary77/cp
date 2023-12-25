#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	string str = "";
	for (int i = 0; i < k; ++i) {
		str.push_back('a'+i);
		str.push_back('a'+i);
	}
	for (int i = k-1; i >= 0; --i) {
		for (int j = i+2; j < k; ++j) {
			str.push_back('a'+j);
			str.push_back('a'+i);
		}
		str.push_back('a'+i-1);
	}
	str.erase(str.end()-1);
	str.erase(str.end()-1);
	for (int i = 0; i < n/(k*k); ++i) {
		cout << str;
	}
	cout << string(str.begin(),str.begin()+(n%(k*k)));
	return 0;
}