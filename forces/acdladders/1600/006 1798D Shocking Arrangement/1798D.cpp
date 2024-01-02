#include <bits/stdc++.h>
using namespace std;

multiset<int> mltst;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		bool onlyzeros = true;
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			mltst.insert(a);
			if (a)onlyzeros = false;
		}
		if (onlyzeros) {
			printf("No\n");
			mltst.clear();
			continue;
		}
		printf("Yes\n");
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			if (cur >= 0) {
				printf("%d ",*mltst.begin());
				cur += *mltst.begin();
				mltst.erase(mltst.begin());
			} else {
				printf("%d ",*--mltst.end());
				cur += *--mltst.end();
				mltst.erase(--mltst.end());
			}
		}
		printf("\n");
	}
	return 0;
}