#include <bits/stdc++.h>
using namespace std;

int pos[200001];
int cnt[200001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		pos[a] = i;
	}
	int max1 = 0;
	for (int i = 0; i < n; ++i) {
		int b;
		scanf("%d",&b);
		int d = (pos[b]-i+n)%n;
		++cnt[d];
		max1 = max(max1,cnt[d]);
	}
	printf("%d\n",max1);
	return 0;
}