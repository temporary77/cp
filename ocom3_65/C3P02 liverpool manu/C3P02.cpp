#include <bits/stdc++.h>
using namespace std;

const int N = 1000*(1 << 10)+1;
bool arr[N];
int tree[2010001];
pair<int,int> lazy[2010001];
int n = 0;
int x, y;
int iter = 0;

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
	if (lazy[chld].first == 0) {
		lazy[chld] = lazy[n];
	} else {
		int dn, rn;
		if (lazy[n].second > lazy[chld].second) {
			dn = n;
			rn = chld;
		} else {
			dn = chld;
			rn = n;
		}
		lazy[rn].second = lazy[dn].second;
		if (lazy[dn].first > 0) {
			lazy[rn].first = lazy[dn].first;
		} else {
			lazy[rn].first = (3-lazy[rn].first)%4;
		}
	}
	return;
}

void update(int n, int a, int b, int val) {
	if (lazy[n].first != 0) {
		if (lazy[n].first == 1)tree[n] = b-a+1;
		else if (lazy[n].first == 2)tree[n] = 0;
		else if (lazy[n].first == -1)tree[n] = b-a+1-tree[n];
		//printf("NODE %d NOW %d\n",n,tree[n]);
		if (a != b) {
			lazyupd(n,2*n);
			lazyupd(n,2*n+1);
		}
		lazy[n] = {0,0};
	}
	if (a > b || b < x || a > y) {
		return;
	}
	if (a >= x && b <= y) {
		if (val == 1)tree[n] = b-a+1;
		else if (val == 2)tree[n] = 0;
		else if (val == -1)tree[n] = b-a+1-tree[n];
		lazy[n] = {val,iter};
		if (a != b) {
			lazyupd(n,2*n);
			lazyupd(n,2*n+1);
		}
		lazy[n] = {0,0};
		return;
	}
	update(2*n,a,(a+b)/2,val);
	update(2*n+1,(a+b)/2+1,b,val);
	tree[n] = tree[2*n]+tree[2*n+1];
}

int query(int n, int a, int b) {
	if (lazy[n].first != 0) {
		if (lazy[n].first == 1)tree[n] = b-a+1;
		else if (lazy[n].first == 2)tree[n] = 0;
		else if (lazy[n].first == -1)tree[n] = b-a+1-tree[n];
		//printf("NODE %d NOW %d\n",n,tree[n]);
		if (a != b) {
			lazyupd(n,2*n);
			lazyupd(n,2*n+1);
		}
		lazy[n] = {0,0};
	}
	if (a > b || b < x || a > y) {
		return 0;
	}
	if (a >= x && b <= y) {
		return tree[n];
	}
	return query(2*n,a,(a+b)/2)+query(2*n+1,(a+b)/2+1,b);
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m;
	scanf("%d",&m);
	int t;
	string str;
	for (int i = 0; i < m; ++i) {
		scanf("%d",&t);
		cin >> str;
		for (int j = 0; j < t; ++j) {
			for (int k = 0; k < str.size(); ++k) {
				arr[n] = 48-str[k];
				++n;
			}
		}
	}
	build(1,0,n-1);
	/*for (int i = 0; i < n; ++i) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ",tree[i]);
	}
	printf("\n");*/
	int q;
	scanf("%d",&q);
	char c;
	for (iter = 0; iter < q; ++iter) {
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
		/*printf("iteration %d %d %d\n",iter,x,y);
		for (int i = 0; i < n; ++i) {
			printf("%d ",tree[i]);
		}
		printf("\n");*/
	}

	return 0;
}

/*
1 0 1 0 1 0 1 0 1 0 1 0 0 0 1 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1
*/