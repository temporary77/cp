#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("test_input.txt","r",stdin);
	int n, m;
	int a, b, w;
	scanf("%d%d",&n,&m);
	vector<tuple<int,int,int>> vctr;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&w);
		vctr.push_back({w,--a,--b});
	}
	int arr[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = INT_MAX;
	}
	arr[0] = 0;
	for (int i = 0; i < n; ++i) {
		bool changed = 0;
		for (auto it : vctr) {
			w = get<0>(it);
			a = get<1>(it);
			b = get<2>(it);
			if (arr[a] != INT_MAX && arr[b] > arr[a]+w) {
				arr[b] = arr[a]+w;
				changed = 1;
			}
		}
		if (changed && i == n-1) {
			printf("neg cycle");
			return 0;
		} else if (!changed) {
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n",i+1,arr[i]);
	}
	return 0;
}