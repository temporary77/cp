#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int l = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > arr[l]) {
			++l;
		}
	}
	printf("%d",l);
	return 0;
}