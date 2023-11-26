#include <bits/stdc++.h>
using namespace std;

map<double,int> mp;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		cin >> str;
		int dcnt = 0;
		int kcnt = 0;
		for (auto it : str) {
			if (it == 'D')++dcnt;
			else if (it == 'K')++kcnt;
			double idx;
			if (kcnt == 0)idx = -1;
			else idx = dcnt/(double)kcnt;
			printf("%d ",++mp[idx]);
		}
		printf("\n");
		mp.clear();
	}
	return 0;
}