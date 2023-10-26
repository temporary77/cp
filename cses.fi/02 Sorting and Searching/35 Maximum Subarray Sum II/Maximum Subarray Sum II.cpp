#include <bits/stdc++.h>
using namespace std;

long long tree[800001];
long long qs[200001];
int n, a, b;

void build(int n1, int a1, int b1) {
	if (a1 > b1) {
		return;
	}
	if (a1 == b1) {
		tree[n1] = qs[a1];
		return;
	}
	build(2*n1,a1,(a1+b1)/2);
	build(2*n1+1,(a1+b1)/2+1,b1);
	tree[n1] = max(tree[2*n1],tree[2*n1+1]);
	return;
}

int x, y;

long long query(int n1, int a1, int b1) {
	if (a1 > b1 || b1 < x || y < a1) {
		return LLONG_MIN;
	}
	if (x <= a1 && b1 <= y) {
		return tree[n1];
	}
	return max(query(2*n1,a1,(a1+b1)/2),query(2*n1+1,(a1+b1)/2+1,b1));
}

int main() {
	scanf("%d%d%d",&n,&a,&b);
	long long k;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld",&k);
		qs[i] = qs[i-1]+k;
	}
	build(1,1,n);
	long long ans = LLONG_MIN;
	for (int i = 1; i+a-1 <= n; ++i) {
		x = i+a-1;
		y = min(i+b-1,n);
		/*long long cald = query(1,1,n)-qs[i-1];
		if (cald > ans) {
			printf("%d %d %d %lld\n",i,x,y,cald);
		}*/
		ans = max(ans,query(1,1,n)-qs[i-1]);
	}
	printf("%lld",ans);
	return 0;
}