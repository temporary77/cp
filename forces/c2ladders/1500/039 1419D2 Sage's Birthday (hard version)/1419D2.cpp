#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;
int arr[100001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		vctr.push_back(a);
	}
	sort(vctr.begin(),vctr.end());
	int idx = 0;
	for (int i = 1; i < n; i += 2) {
		arr[i] = vctr[idx];
		++idx;
	}
	for (int i = 0; i < n; i += 2) {
		arr[i] = vctr[idx];
		++idx;
	}
	int ans = 0;
	for (int i = 1; i < n-1; ++i) {
		if (arr[i-1] > arr[i] && arr[i] < arr[i+1]) {
			++ans;
		}
	}
	printf("%d\n",ans);
	for (int i = 0; i < n; ++i) {
		printf("%d ",arr[i]);
	}
	return 0;
}