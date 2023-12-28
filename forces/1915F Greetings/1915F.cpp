#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int n;

vector<pair<int,int>> vctr;
int tree[200001];

bool comp(pair<int,int> x, pair<int,int> y) {
	return x.f > y.f;
}

bool comp2(pair<int,int> x, pair<int,int> y) {
	return x.s < y.s;
}

void update(int x) {
	for (int i = x; i <= n; i += i&-i) {
		++tree[i];
	}
	return;
}

int query(int x) {
	int res = 0;
	for (int i = x; i > 0; i -= i&-i) {
		res += tree[i];
	}
	return res;
}

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			int a, b;
			scanf("%d%d",&a,&b);
			vctr.push_back({a,b});
		}
		for (int i = 1; i <= n; ++i)tree[i] = 0;
		sort(vctr.begin(),vctr.end(),comp2);
		for (int i = 0; i < n; ++i) {
			vctr[i].s = i+1;
		}
		sort(vctr.begin(),vctr.end(),comp);
		long long ans = 0;
		for (auto it : vctr) {
		 	ans += query(it.s);
			update(it.s);
		}
		printf("%lld\n",ans);
		vctr.clear();
	}
	return 0;
}