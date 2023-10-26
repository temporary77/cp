#include <bits/stdc++.h>
using namespace std;

pair<int,long long> arr[100001];
pair<int,long long> tree[400001];
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

pair<int, long long> query(int n, int a, int b) {
	if (a > b || b < x || y < a) {
		return {INT_MIN,0};
	}
	if (x <= a && b <= y) {
		return tree[n];
	}
	pair<int, long long> q1, q2;
	q1 = query(2*n,a,(a+b)/2);
	q2 = query(2*n+1,(a+b)/2+1,b);
	return {max(q1.first,q2.first),q1.second+q2.second};
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
	pair<int,long long> ans;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&x,&y);
		ans = query(1,0,n-1);
		printf("%d %lld\n",ans.first,ans.second);
	}
	return 0;
}