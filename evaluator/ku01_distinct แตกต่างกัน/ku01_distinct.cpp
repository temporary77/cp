#include <bits/stdc++.h>
using namespace std;

set<int> st;
int qs[101];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&qs[i]);
 		qs[i] += qs[i-1];
 		for (int j = 0; j < i; ++j) {
 			st.insert(qs[i]-qs[j]);
 		}
	}
	printf("%d",st.size());
	return 0;
}