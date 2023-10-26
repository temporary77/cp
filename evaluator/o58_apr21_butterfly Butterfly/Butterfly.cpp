#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, q;
	scanf("%d%d",&k,&q);
	for (int i = 0; i < q; ++i) {
		long long anode, bnode;
		int afloor, bfloor;
		scanf("%lld %d %lld %d",&anode,&afloor,&bnode,&bfloor);
		long long abxor = anode^bnode;
		int cmmnflr = 0;
		for (;;) {
			if (abxor <= 0)break;
			abxor = abxor >> 1;
			++cmmnflr;
		}
		if (cmmnflr == 0) {
			printf("%d\n",abs(afloor-bfloor));
			continue;
		}
		int cnt = 0;
		//printf("cg %d\n",cmmnflr);
		if (afloor >= cmmnflr && bfloor >= cmmnflr) {
			cnt += abs(afloor-bfloor);
			cmmnflr = min(afloor,bfloor);
		} else if (afloor <= cmmnflr && bfloor >= cmmnflr) {
			cnt += bfloor-afloor;
			cmmnflr = afloor;
		} else if (bfloor <= cmmnflr && afloor >= cmmnflr) {
			cnt += afloor-bfloor;
			cmmnflr = bfloor;
		} else {
			cnt += (cmmnflr-afloor)+(cmmnflr-bfloor);
			cmmnflr = min(afloor,bfloor);
		}
		abxor = anode^bnode;
		int intrsctflr = log2(abxor&-abxor);
		//printf("intersect %d\n",intrsctflr);
		if (intrsctflr < cmmnflr) {
			cnt += 2*(cmmnflr-intrsctflr);
		}
		printf("%d\n",cnt);
	}



	return 0;
}