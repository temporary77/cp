#include <bits/stdc++.h>
using namespace std;

bool arr[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		fill(arr,arr+n+1,false);
		arr[0] = true;
		for (int i = 0; i < n; ++i) {
			int b;
			scanf("%d",&b);
			if (arr[i]) {
				if (i+b+1 <= n)arr[i+b+1] = true;
			}
			if (i-b >= 0 && arr[i-b])arr[i+1] = true;
		}
		if (arr[n])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}