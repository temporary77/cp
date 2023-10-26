#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("test_input2.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	int arm[n], lead[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arm[i]);
		lead[i] = i;
	}
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		--a;
		--b;
		int ai = a;
		int bi = b;
		for (; lead[a] != a;) {
			a = lead[a];
		}
		for (; lead[b] != b;) {
			b = lead[b];
		}
		if (a == b) {
			printf("-1\n");
			continue;
		}
		if (arm[a] > arm[b] || (arm[a] == arm[b] && a < b)) {	
			lead[b] = a;
			lead[bi] = a;
			arm[a] += arm[b]/2;
			printf("%d\n",a+1);
			continue;
		}
		if (arm[a] < arm[b] || (arm[a] == arm[b] && b < a)) {
			lead[a] = b;
			lead[ai] = b;
			arm[b] += arm[a]/2;
			printf("%d\n",b+1);
			continue;
		}

	}
	return 0;
}