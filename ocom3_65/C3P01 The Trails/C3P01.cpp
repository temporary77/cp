#include <bits/stdc++.h>
using namespace std;

pair<int,long long> arr[1000001];
pair<int,long long> tree[1000001];
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
	tree[n].first = max(tree[2*n].first,tree[2*n+1].first);
	tree[n].second = tree[2*n].second+tree[2*n+1].second;
	return;
}

pair<int,long long> query(int n, int a, int b) {
	//printf("node %d %d %d %d %d\n",n,a,b,x,y);
	if (a > b || b < x || a > y) {
		return {INT_MIN,0};
	}
	if (a >= x && b <= y) {
		//printf("base accessed%d \n",n);
		return tree[n];
	}
	pair<int,long long> q1 = query(2*n,a,(a+b)/2);
	pair<int,long long> q2 = query(2*n+1,(a+b)/2+1,b);
	pair<int,long long> res;
	res.first = max(q1.first,q2.first);
	res.second = q1.second+q2.second;
	return res;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i].first);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arr[i].second);
	}
	build(1,0,n-1);
	/*for (int i = 0; i <= n; ++i) {
		printf("%d ",tree[i].first);
	}
	printf("\n");
	for (int i = 0; i <= n; ++i) {
		printf("%d ",tree[i].second);
	}
	printf("\n");*/
	pair<int,long long> ans;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&x,&y);
		ans = query(1,0,n-1);
		printf("%d %lld\n",ans.first,ans.second);
	}

	return 0;
}