#include <bits/stdc++.h>
using namespace std;

int arr[200001];
int max1[200001];
set<int> st;
vector<int> vctr;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		for (int i = 0; i <= n; ++i) {
			st.insert(i);
		}
		for (int i = n-1; i >= 0; --i) {
			st.erase(arr[i]);
			max1[i] = *st.begin();
		}
		st.clear();
		int l = 0;
		for (int i = 0; i < n; ++i) {
			if (arr[i] < max1[l]) {
				st.insert(arr[i]);
			}
			if (st.size() == max1[l]) {
				st.clear();
				vctr.push_back(max1[l]);
				l = i+1;
			}
		}
		printf("%d\n",vctr.size());
		for (auto it : vctr) {
			printf("%d ",it);
		}
		printf("\n");
		st.clear();
		vctr.clear();
	}
	return 0;
}