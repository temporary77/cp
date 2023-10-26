#include <bits/stdc++.h>
using namespace std;

set<int> st;

int main() {
	int x;
	for (int i = 0; i < 10; ++i) {
		scanf("%d",&x);
		st.insert(x%42);
	}
	printf("%d",st.size());
	return 0;
}