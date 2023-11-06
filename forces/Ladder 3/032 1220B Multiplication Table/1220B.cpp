#include <bits/stdc++.h>
using namespace std;

int row[1001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&row[i]);
	}
	long long k;
	scanf("%*lld%*lld%lld",&k);
	int a;
	a = (int)sqrt(((long long)row[1]*row[2]/k));
	printf("%d ",a);
	for (int i = 1; i < n; ++i) {
		printf("%d ",row[i]/a);
	}
	return 0;
}