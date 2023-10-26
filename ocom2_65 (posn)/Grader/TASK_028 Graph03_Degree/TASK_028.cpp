#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	pair<int,int> arr[n] = {{0,0}};
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		++arr[--a].second;
		++arr[--b].first;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n",arr[i].first,arr[i].second);
	}
	return 0;
}