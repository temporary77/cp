#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	int n;
	scanf("%d",&n);
	int x;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&x);
		vctr.push_back(x);
	}
	sort(vctr.begin(),vctr.end());
	int m;
	scanf("%d",&m);
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		int k;
		scanf("%d",&k);
		vector<int> vctr2;
		int b;
		for (int j = 0; j < k; ++j) {
			scanf("%d",&b);
			vctr2.push_back(b);
		}
		sort(vctr2.begin(),vctr2.end());
		vector<int> vctr3;
		set_intersection(vctr.begin(),vctr.end(),vctr2.begin(),vctr2.end(),back_inserter(vctr3));
		if (vctr3.size() == 0)++cnt;
	}
	printf("%d",cnt);
	return 0;
}

/*
2 1 2
4
2 1 4
3 1 2 3
2 3 4
3 3 5 7
*/