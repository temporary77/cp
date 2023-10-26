#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200001];
long long tree[800001];
pair<long long,int> lazy[800001];

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

void update(int n, int a, int b, int x, int y) {
	if (lazy[n] != (pair<long long,int>){0,0}) {
		long long z = lazy[n].first;
		int d = lazy[n].second;
		// printf("%lld %d %d %d\n",z,d,a,b);
		tree[n] += (2*z+(b-a)*d)*(b-a+1)/2;
		if (a != b) {
			lazy[2*n].first += z;
			lazy[2*n].second += d;
			lazy[2*n+1].first += z+((a+b)/2-a+1)*d;
			lazy[2*n+1].second += d;
		}
		lazy[n].first = 0;
		lazy[n].second = 0;
	}
	// printf("%lld >>>> %d %d\n",tree[n],a,b);
	if (a > b || b < x || y < a) {
		return;
	}
	if (x <= a && b <= y) {
		// printf("%d %d %d %d\n",x,a,b,y);
		long long z = a-x+1;
		// printf("%lld\n",(2*z+(b-a))*(b-a+1)/2);
		// printf("%lld\n",z);
		tree[n] += (2*z+(b-a))*(b-a+1)/2;
		if (a != b) {
			lazy[2*n].first += z;
			lazy[2*n].second += 1;
			lazy[2*n+1].first += z+(a+b)/2-a+1;
			lazy[2*n+1].second += 1;
		}
		// printf("%d %d %lld\n",a,b,tree[n]);
	// printf("%lld << %d %d\n",tree[n],a,b);
		return;
	}
	update(2*n,a,(a+b)/2,x,y);
	update(2*n+1,(a+b)/2+1,b,x,y);
	tree[n] = tree[2*n]+tree[2*n+1];
	// printf("%lld <<<< %d %d\n",tree[n],a,b);
	return;
}

long long query(int n, int a, int b, int x, int y) {
	if (lazy[n] != (pair<long long,int>){0,0}) {
		long long z = lazy[n].first;
		int d = lazy[n].second;
		// printf("%lld %d %d %d\n",z,d,a,b);
		tree[n] += (2*z+(b-a)*d)*(b-a+1)/2;
		if (a != b) {
			lazy[2*n].first += z;
			lazy[2*n].second += d;
			lazy[2*n+1].first += z+((a+b)/2-a+1)*d;
			lazy[2*n+1].second += d;
		}
		lazy[n].first = 0;
		lazy[n].second = 0;
	}
	if (a > b || b < x || y < a) {
		// printf("%d %d %lld\n",a,b,tree[n]);
		return 0;
	}
	if (x <= a && b <= y) {
		// printf("%d %d %lld\n",a,b,tree[n]);
		return tree[n];
	}
	return query(2*n,a,(a+b)/2,x,y)+query(2*n+1,(a+b)/2+1,b,x,y); 
}

int main() {
	int q;
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	build(1,1,n);
	for (int i = 0; i < q; ++i) {
		int k;
		scanf("%d",&k);
		if (k == 1) {
			int x, y;
			scanf("%d%d",&x,&y);
			update(1,1,n,x,y);
			// printf("upd\n");
		} else if (k == 2) {
			int x, y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,1,n,x,y));
		}
	}

	return 0;
}