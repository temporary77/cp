#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

class comp {
public:
	bool operator()(pair<int,int> a, pair<int,int> b) {
		if (a.f != b.f) {
			return a.f < b.f;
		} else {
			return a.s > b.s;
		}
	}
};

int ans[200001];
priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		pq.push({n,1});
		for (int i = 1; i <= n; ++i) {
			int w, l;
			tie(w,l) = pq.top();
			pq.pop();
			int m = l+(w-1)/2;
			ans[m] = i;
			if (m != l)pq.push({m-l,l});
			if (l+w-1 != m)pq.push({l+w-1-m,m+1});
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}