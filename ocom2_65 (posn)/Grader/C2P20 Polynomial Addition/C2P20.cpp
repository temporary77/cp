#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	map<int,int> mp;
	for (int i = 0; i < n; ++i) {
		int p, c;
		scanf("%d%d",&p,&c);
		mp[p] += c;
	}
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		int p, c;
		scanf("%d%d",&p,&c);
		mp[p] += c;
		if (mp[p] == 0)mp.erase(p);
	}
	if (mp.empty()) {
		printf("0");
		return 0;
	}
	for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
		printf("%d %d\n",it->first,it->second);
	}
	return 0;
}