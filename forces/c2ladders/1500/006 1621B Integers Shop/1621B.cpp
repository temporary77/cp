#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int l = INT_MAX;
		int r = INT_MIN;
		pair<int,int> pl;
		pair<int,int> pr;
		tuple<int,int,int> tpl = {INT_MAX,INT_MIN,0};
		for (int i = 0; i < n; ++i) {
			int li, ri, ci;
			scanf("%d%d%d",&li,&ri,&ci);
			if (li <= l) {
				if (li == l) {
					if (ci < pl.f) {
						pl = {ci,i};
					}
				} else {
					pl = {ci,i};
				}
				l = li;
			}
			if (r <= ri) {
				if (ri == r) {
					if (ci < pr.f) {
						pr = {ci,i};
					}
				} else {
					pr = {ci,i};
				}
				r = ri;
			}
			if (li <= get<0>(tpl) && get<1>(tpl) <= ri) {
				if (li == get<0>(tpl) && ri == get<1>(tpl)) {
					get<2>(tpl) = min(get<2>(tpl),ci);
				} else {
					tpl = {li,ri,ci};
				}
			}
			// printf("%d %d {%d,%d} {%d,%d} {%d,%d,%d} = ",l,r,pl,pr,get<0>(tpl),get<1>(tpl),get<2>(tpl));
			int ans1;
			if (get<0>(tpl) <= l && r <= get<1>(tpl)) {
				ans1 = get<2>(tpl);
			} else {
				ans1 = INT_MAX;
			}
			int ans2;
			if (pl.s == pr.s) {
				ans2 = pl.f;
			} else {
				ans2 = pl.f+pr.f;
			}			
			printf("%d\n",min(ans1,ans2));
		}
	}
	return 0;
}