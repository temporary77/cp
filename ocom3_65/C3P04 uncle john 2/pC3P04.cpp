#include <bits/stdc++.h>
using namespace std;

int tree[400001];
bool lazy[400001];
int s, t;

void update(int n, int a, int b) {
	if (lazy[n] != 0) {
		tree[n] = b-a+1-tree[n];
		if (a != b) {
			lazy[2*n] ^= 1;
			lazy[2*n+1] ^= 1;
		}
		lazy[n] = 0;
	}
	if (a > b || t < a || b < s) {
		return;
	}
	if (s <= a && b <= t) {
		tree[n] = b-a+1-tree[n];
		if (a != b) {
			lazy[2*n] ^= 1;
			lazy[2*n+1] ^= 1;
		}
		return;
	}
	update(2*n,a,(a+b)/2);
	update(2*n+1,(a+b)/2+1,b);
	tree[n] = tree[2*n]+tree[2*n+1];
	return;
}

int query(int n, int a, int b) {
	if (lazy[n] != 0) {
		tree[n] = b-a+1-tree[n];
		if (a != b) {
			lazy[2*n] ^= 1;
			lazy[2*n+1] ^= 1;
		}
		lazy[n] = 0;
	}
	if (a > b || t < a || b < s) {
		return 0;
	}
	if (s <= a && b <= t) {
		return tree[n];
	}
	int q1 = query(2*n,a,(a+b)/2);
	int q2 = query(2*n+1,(a+b)/2+1,b);
	//printf("%d %d\n",q1,q2);
	return q1+q2;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int k;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&k,&s,&t);
		if (k == 0) {
			update(1,0,n-1);
		} else if (k == 1) {
			printf("%d\n",query(1,0,n-1));
		}
	}
	return 0;
}