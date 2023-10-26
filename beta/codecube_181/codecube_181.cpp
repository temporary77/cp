#include <bits/stdc++.h>
using namespace std;

int n, m, p;
vector<tuple<int,int,int>> vctr;
vector<pair<int,int>> vctr2;
int dj[40001];

int main() {
	scanf("%d%d%d",&n,&m,&p);
	int a, b, x;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&x);
		vctr.push_back({x,--a,--b});
	}
	for (int i = 0; i < p; ++i) {
		scanf("%d%d",&a,&b);
		vctr2.push_back({--a,--b});
	}
	sort(vctr.begin(),vctr.end());
	int l = 1, r = 1e9;
	for (;;) {
		if (l >= r)break;
		int mid = (l+r)/2;
		if ((l+r)%2)++mid;
		//printf("%d %d %d <<<<<<<<<<<,\n",l,r,mid);
		for (int i = 0; i < n; ++i)dj[i] = i;
		for (auto it = --lower_bound(vctr.begin(),vctr.end(),(tuple<int,int,int>){mid,0,0}); it != vctr.begin()-1; --it) {
			a = get<1>(*it);
			b = get<2>(*it);
			//printf("%d %d %d <\n",get<0>(*it),a,b);
			int pa = a;
			int pb = b;
			for (;dj[pa] != pa; pa = dj[pa]);
			for (;dj[pb] != pb; pb = dj[pb]);
			if (pa != pb) {
				dj[pb] = pa;
				dj[b] = pa;
			}
		}
		for (auto it : vctr2) {
			a = it.first;
			b = it.second;
			for (;dj[a] != a; a = dj[a]);
			for (;dj[b] != b; b = dj[b]);
			if (a == b) {
				r = mid-1;
				break;
			}
		}
		if (r != mid-1)l = mid;
	}
	if (l == 1e9)printf("-1");
	else printf("%d",l);
	return 0;
}