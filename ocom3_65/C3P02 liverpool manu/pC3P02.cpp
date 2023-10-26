#include <bits/stdc++.h>
using namespace std;

bool arr[1024001];
int tree[4096001];
int lazy[4096001];
int n = 0;
int x, y;

void build(int n, int a, int b) {
	if (a > b) {
		return;
	}
	if (a == b) {
		tree[n] = arr[a];
		return;
	}
	build(2*n,a,(a+b)/2);
	build(2*n+1,(a+b)/2+1,b);
	tree[n] = tree[2*n]+tree[2*n+1];
	return;
}

void lazyupd(int n, int chld) {
	if (lazy[chld] == 0 || lazy[n] == 1 || lazy[n] == 2) {
		lazy[chld] = lazy[n];
		return;
	}
	if (lazy[chld] == 1) {
		lazy[chld] = 2;
	} else if (lazy[chld] == 2) {
		lazy[chld] = 1;
	} else if (lazy[chld] == -1) {
		lazy[chld] = 0;
	}
	return;
}

void update(int n, int a, int b, int val) {
	if (lazy[n] != 0) {
		if (lazy[n] == 1) {
			tree[n] = b-a+1;			
		} else if (lazy[n] == 2) {
			tree[n] = 0;
		} else if (lazy[n] == -1) {
			tree[n] = b-a+1-tree[n];
		}
		if (a != b) {
			lazyupd(n,2*n);
			lazyupd(n,2*n+1);
		}
		lazy[n] = 0;
	}
	if (a > b || b < x || y < a) {
		return;
	}
	if (x <= a && b <= y) {
		if (val == 1) {
			tree[n] = b-a+1;			
		} else if (val == 2) {
			tree[n] = 0;
		} else if (val == -1) {
			tree[n] = b-a+1-tree[n];
		}
		lazy[n] = val;
		if (a != b) {
			lazyupd(n,2*n);
			lazyupd(n,2*n+1);
		}
		lazy[n] = 0;
		return;
	}
	update(2*n,a,(a+b)/2,val);
	update(2*n+1,(a+b)/2+1,b,val);
	tree[n] = tree[2*n]+tree[2*n+1];
	return;
}

int query(int n, int a, int b) {
	if (lazy[n] != 0) {
		if (lazy[n] == 1) {
			tree[n] = b-a+1;			
		} else if (lazy[n] == 2) {
			tree[n] = 0;
		} else if (lazy[n] == -1) {
			tree[n] = b-a+1-tree[n];
		}
		if (a != b) {
			lazyupd(n,2*n);
			lazyupd(n,2*n+1);
		}
		lazy[n] = 0;
	}
	if (a > b || b < x || y < a) {
		return 0;
	}
	if (x <= a && b <= y) {
		return tree[n];
	}
	int q1, q2;
	q1 = query(2*n,a,(a+b)/2);
	q2 = query(2*n+1,(a+b)/2+1,b);
	return q1+q2;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	scanf("%d",&m);
	int t;
	string str;
	for (int i = 0; i < m; ++i) {
		scanf("%d",&t);
		cin >> str;
		for (int j = 0; j < t; ++j) {
			for (auto c : str) {
				arr[n] = 48-c;
				++n;
			}
		}
	}
	build(1,0,n-1);
	int q;
	scanf("%d",&q);
	char c;
	for (int i = 0; i < q; ++i) {
		scanf(" %c%d%d",&c,&x,&y);
		if (c == 'F') {
			update(1,0,n-1,1);
		} else if (c == 'E') {
			update(1,0,n-1,2);
		} else if (c == 'I') {
			update(1,0,n-1,-1);
		} else if (c == 'S') {
			printf("%d\n",query(1,0,n-1));
		}
		/*for (int j = 0; j < 4*n; ++j) {
			printf("%d ",tree[j]);
		}
		printf("\n\n");*/
	}
	return 0;
}