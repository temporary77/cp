#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vctr(200002);
int n, k;

int main() {
	scanf("%d",&n);
	int r = 0;
	for (int i = 1; i <= n; ++i) {
		/*printf("\n");
		for (int j = 0; j < r; ++j) {
			printf("%d ",vctr[j].first);
		}
		printf("i \n");*/
		scanf("%d",&k);
		if (i == 1) {
			printf("0 ");
			vctr[0] = {k,1};
			r = 1;
			continue;
		}
		auto it = lower_bound(vctr.begin(),vctr.begin()+r,(pair<int,int>){k,0});
		if (it == vctr.begin()) {
			printf("0 ");
			r = 1;
			vctr[0] = {k,i};
		} else {
			printf("%d ",(*--lower_bound(vctr.begin(),vctr.begin()+r,(pair<int,int>){k,0})).second);
			r = it-vctr.begin()+1;
			vctr[r-1] = {k,i};
		}
	}
	return 0;
}