#include <bits/stdc++.h>
using namespace std;

int arr[200001];
bool taken[200001];
set<int> st;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		fill(taken+1,taken+n+1,false);
		int idx = 1;
		for (int i = 0; i < n; ++i) {
			if (i == 0 || arr[i] != arr[i-1]) {
				printf("%d ",arr[i]);
				taken[arr[i]] = true;
			} else {
				for (;taken[idx];)++idx;
				printf("%d ",idx);
				taken[idx] = true;
			}
		}
		printf("\n");
		int prev = 0;
		for (int i = 0; i < n; ++i) {
			if (i == 0 || arr[i] != arr[i-1]) {
				for (int j = prev+1; j <= arr[i]; ++j)st.insert(j);
				prev = arr[i];
				printf("%d ",arr[i]);
				taken[arr[i]] = true;
			} else {
				printf("%d ",*st.rbegin());
			}
			st.erase(--st.end());
		}
		printf("\n");
	}
	return 0;
}