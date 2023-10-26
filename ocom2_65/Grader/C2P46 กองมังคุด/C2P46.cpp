#include <bits/stdc++.h>
using namespace std;

void update(int* tree, int* arr, int n) {
	for (int i = 0; i < n+1; ++i) {
		tree[i] = 0;
		for (int j = i-(i&-i); j < i; ++j) {
			tree[i] += arr[j];
		}
	}
	return;
}

int main() {
	//freopen("test_input.txt","r",stdin);
	int n, m;
	scanf("%d%d",&n,&m);
	int arr[n];
	int tree[n+1];
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	update(tree,arr,n);
	int a, b;
	long long suma, sumb;
	for (int i = 0; i < m; ++i) {
		suma = 0;
		sumb = 0;
		scanf("%d%d",&a,&b);
		++b;
		for (;a > 0;) {
			suma += tree[a];
			a -= a & -a;
		}
		for (;b > 0;) {
			sumb += tree[b];
			b -= b & -b;
		}
		printf("%lld\n",sumb-suma);
	}
	return 0;
}