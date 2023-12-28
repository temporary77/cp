#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			if (a == 1) {
				vctr.push_back(a);
			} else {
				for (;*vctr.rbegin() != a-1;) {
					vctr.erase(vctr.end()-1);
				}
				vctr.erase(vctr.end()-1);
				vctr.push_back(a);
			}
			for (int i = 0; i < vctr.size(); ++i) {
				printf("%d",vctr[i]);
				if (i < vctr.size()-1)printf(".");
			}
			printf("\n");
		}
		vctr.clear();
	}
	return 0;
}