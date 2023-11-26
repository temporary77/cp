#include <bits/stdc++.h>
using namespace std;

int pos[200001];

int main() {
	cin.tie(NULL);
	int n, m;
	scanf("%d%d",&n,&m);
	string s, t;
	cin >> s >> t;
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[idx]) {
			pos[idx] = i;
			if (++idx == n)break;
		}
	}
	idx = m-1;
	int ans = 1;
	for (int i = n-1; i >= 0; --i) {
		if (s[i] == t[idx]) {
			ans = max(ans,i-pos[idx-1]);
			if (--idx == 0)break;
		}
	}
	printf("%d\n",ans);
	return 0;
}