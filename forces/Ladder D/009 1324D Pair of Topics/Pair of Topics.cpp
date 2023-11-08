#include <bits/stdc++.h>
using namespace std;

int arr[200001];
vector<int> tree[200001];
int n;

void build() {
	for (int i = 1; i <= n; ++i) {
		for (int j = i-(i&-i)+1; j <= i; ++j) {
			// printf("%d %d <\n",i,j);
			tree[i].push_back(arr[j-1]*-1);
		}
		sort(tree[i].begin(),tree[i].end());
	}
	return;
}

long long query(int x, int val) {
	long long res = 0;
	for (int a = x; a > 0; a -= a&-a) {
		res += lower_bound(tree[a].begin(),tree[a].end(),val)-tree[a].begin();
		// printf("%d %d %d\n",x,val,res);
	}
	return res;
}

int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		arr[i] -= k;
	}
	build();
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += query(i,arr[i]);	
		// printf("%d\n",ans);
	}
	printf("%lld",ans);
	return 0;
}