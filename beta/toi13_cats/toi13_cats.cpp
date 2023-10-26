#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int k;
	int a, ans = INT_MAX;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		if (st.find(k) != st.end()) {
			st.erase(k);
		} else {
			st.insert(k);
			if (st.size() >= 2) {
				a = *(++st.rbegin());
			}
		}
		if (st.size() == 0) {
			ans = min(ans,a);
			a = INT_MAX;
		}
	}

	
	printf("%d",ans);
	return 0;
}