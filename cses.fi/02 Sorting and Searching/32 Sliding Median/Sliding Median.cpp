#include <bits/stdc++.h>
using namespace std;

int arr[200001];
vector<int> vctr;
multiset<int> st, st2;

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		if (i < k) {
			vctr.push_back(arr[i]);
		}
	}
	sort(vctr.begin(),vctr.end());
	int m = (k-1)/2;
	for (int i = 0; i <= m; ++i) {
		st.insert(vctr[i]);
	}
	for (int i = m+1; i < k; ++i) {
		st2.insert(vctr[i]);
	}
	/*for (auto it : st) {
		printf("%d ",it);
	}
	printf("\n");
	for (auto it : st2) {
		printf("%d ",it);
	}
	printf("\n");*/
	printf("%d ",*st.rbegin());
	for (int i = k; i < n; ++i) {
		//printf("------- %d %d %d\n",i,arr[i-k],arr[i]);
		if (st.find(arr[i-k]) != st.end()) {
			st.erase(st.find(arr[i-k]));
			if (st2.empty() || arr[i] <= *st2.begin()) {
				st.insert(arr[i]);
			} else {
				st.insert(*st2.begin());
				st2.erase(st2.begin());
				st2.insert(arr[i]);
			}
		} else {
			st2.erase(st2.find(arr[i-k]));
			if (st.empty() || arr[i] >= *st.rbegin()) {
				st2.insert(arr[i]);
			} else {
				st2.insert(*st.rbegin());
				st.erase(--st.end());
				st.insert(arr[i]);
			}
		}
	/*for (auto it : st) {
		printf("%d ",it);
	}
	printf("\n");
	for (auto it : st2) {
		printf("%d ",it);
	}
	printf("\n");*/
		printf("%d ",*st.rbegin());
	}
	return 0;
}