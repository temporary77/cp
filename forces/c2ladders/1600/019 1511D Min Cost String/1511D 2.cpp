#include <bits/stdc++.h>
using namespace std;

int cnt[26];
string str = "";

int n, k;

void eulerpath(int x) {
	for (;cnt[x] < k;) {
		++cnt[x];
		eulerpath(cnt[x]-1);
	}
	str.push_back('a'+x);
	return;
}

int main() {
	scanf("%d%d",&n,&k);
	eulerpath(0);
	str.erase(str.end()-1);
	for (int i = 0; i < n/(k*k); ++i) {
		cout << str;
	}
	cout << string(str.begin(),str.begin()+n%(k*k));
	return 0;
}