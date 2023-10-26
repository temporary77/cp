#include <bits/stdc++.h>
using namespace std;

int arr[100001];
vector<int> tree[100001];
int n, q;

void build() {
	for (int i = 1; i <= n; ++i) {
		for (int j = i-(i&-i)+1; j <= i; ++j) {
			tree[i].insert(upper_bound(tree[i].begin(),tree[i].end(),arr[j]),arr[j]);
		}
	}
	return;
}

void update(int a, int x) {
	int d = arr[a];
	arr[a] = x;
	for (int i = a; i <= n; i += i&-i) {
		auto it = lower_bound(tree[i].begin(),tree[i].end(),d);
		auto it2 = upper_bound(tree[i].begin(),tree[i].end(),x);
		*it = x;
		if (it < it2) {
			rotate(it,it+1,it2);			
		} else {
			rotate(it2,it,it+1);
		}
	}
	return;
}

int query(int a, int b, int x) {
	int sa = 0, sb = 0;
	--a;
	for (;;) {
		if (a == b)break;
		if (b > a) {
			sb += upper_bound(tree[b].begin(),tree[b].end(),x)-tree[b].begin();
			b -= b&-b;
		} else {
			sa += upper_bound(tree[a].begin(),tree[a].end(),x)-tree[a].begin();
			a -= a&-a;
		}
	}
	return sb-sa;
}

int main() {
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	build();
	char c;
	int a, b, x;
	for (int i = 0; i < q; ++i) {
		scanf(" %c",&c);
		//printf("%c",c);
		if (c == 'C') {
			scanf("%d%d%d",&a,&b,&x);
			printf("%d\n",query(a,b,x));
		} else if (c == 'M') {
			scanf("%d%d",&a,&x);
			update(a,x);
		}
	}
	return 0;
}