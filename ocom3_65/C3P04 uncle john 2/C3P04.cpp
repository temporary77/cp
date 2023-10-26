#include <bits/stdc++.h>
using namespace std;

int tree[400004];
bool lazy[400004];
int nn, m;
int x, y;

void update(int n, int a, int b) {
	if (lazy[n] != 0) {
		tree[n] = b-a+1-tree[n];
		if (a != b) {
			lazy[2*n] ^= 1;
			lazy[2*n+1] ^= 1;
		}
		lazy[n] = 0;		
	}
	if (a > b || b < x || y < a) {
		return;
	}
	if (x <= a && b <= y) {
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
	if (a > b || b < x || y < a) {
		//printf("%d banished with %d %d %d %d\n",n,a,b,x,y);
		return 0;
	}
	if (x <= a && b <= y) {
		//printf("%d tree is %d\n",n,tree[n]);
		return tree[n];
	}
	int q1 = query(2*n,a,(a+b)/2);
	int q2 = query(2*n+1,(a+b)/2+1,b);
	//printf("%d adding %d and %d\n",n,q1,q2);
	return q1+q2;
}

int main() {
	scanf("%d%d",&nn,&m);
	int mode, a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&mode,&x,&y);
		--x;
		--y;
		//printf("-------tree[1] is %d\n",tree[1]);
		if (mode == 0) {
			update(1,0,nn-1);
		} else if (mode == 1) {
			printf("%d\n",query(1,0,nn-1));
		}
	}
	//printf("success");
	return 0;
}
// 0 0 0 0 0 0 0 1 1 1