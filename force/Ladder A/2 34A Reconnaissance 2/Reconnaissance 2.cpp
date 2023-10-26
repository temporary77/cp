#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	int min = INT_MAX;
	int ans;
	for (int i = 0; i < n; ++i) {
		if (abs(arr[i]-arr[(i+1)%n]) < min) {
			min = abs(arr[i]-arr[(i+1)%n]);
			ans = i;
		}
	}
	printf("%d %d",ans+1,(ans+1)%n+1);
	return 0;
}