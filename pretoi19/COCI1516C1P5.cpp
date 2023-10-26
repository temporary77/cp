#include <bits/stdc++.h>
using namespace std;

int arr[100001], brr[100001];
int dp[100001][21];

int main() {
	int n, c;
	scanf("%d%d",&n,&c);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",arr[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d",brr[i]);
	}

	return 0;
}