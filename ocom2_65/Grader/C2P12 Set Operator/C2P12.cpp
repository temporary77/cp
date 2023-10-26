#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, c, k;
	scanf("%d%d%d",&n,&m,&c);
	set<int> a, b;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		a.insert(k);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d",&k);
		b.insert(k);
	}
	if (c == 0) {
		auto it1 = a.begin();
		auto it2 = b.begin();
		for (;it1 != a.end() && it2 != b.end();) {
			if (*it1 < *it2) {
				printf("%d ",*it1);
				++it1;
			} else if (*it1 > *it2) {
				printf("%d ",*it2);
				++it2;
			} else {
				printf("%d ",*it1);
				++it1;
				++it2;
			}
		}
		for (;it1 != a.end();) {
			printf("%d ",*it1);
			++it1;
		}
		for (;it2 != b.end();) {
			printf("%d ",*it2);
			++it2;
		}
	} else if (c == 1) {
		auto it1 = a.begin();
		auto it2 = b.begin();
		for (;it1 != a.end() && it2 != b.end();) {
			if (*it1 < *it2) {
				++it1;
			} else if (*it1 > *it2) {
				++it2;
			} else {
				printf("%d ",*it1);
				++it1;
				++it2;
			}
		}
	} else if (c == 2) {
		auto it1 = a.begin();
		auto it2 = b.begin();
		for (;it1 != a.end() && it2 != b.end();) {
			if (*it1 < *it2) {
				printf("%d ",*it1);
				++it1;
			} else if (*it1 > *it2) {
				++it2;
			} else {
				++it1;
				++it2;
			}
		}
		for (;it1 != a.end();) {
			printf("%d ",*it1);
			++it1;
		}
	}
	return 0;
}