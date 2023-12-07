#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

long long qs[200001];
set<long long> st;

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d",&a);
		qs[i] = qs[i-1]+a;
	}
	st.insert(0);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (st.find(qs[i]) != st.end()) {
			st.clear();
			st.insert(qs[i-1]);
			++ans;
		}
		st.insert(qs[i]);
	}
	printf("%d\n",ans);
	return 0;
}