#include <bits/stdc++.h>
using namespace std;

int arr[200002];
int n, x;

int main() {
	scanf("%d%d",&n,&x);
	int l = 0;
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		sum += arr[i];
		if (sum == x) {
			++cnt;
		} else if (sum > x) {
			for (;sum > x;) {
				sum -= arr[l];
				++l;
			}
			if (sum == x)++cnt;
		}
	}
	printf("%d",cnt);
	return 0;
}