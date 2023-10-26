#include <bits/stdc++.h>
using namespace std;
 
bool pos[100001];
int cnt = 0;
 
int main() {
	int n, c, d;
	scanf("%d%d%d",&n,&c,&d);
	pos[1] = 1;
	for (int i = 1; i <= n; ++i) {
		if (pos[i]) {
			if(i+c-1 <= n)pos[i+c-1] = 1;
			if(i+d-1 <= n)pos[i+d-1] = 1;
		}
	}
	int k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&k);
		if (k%2 == 1) {
			++cnt;
		}
	}
	if (cnt%2 == 1 && pos[n] == 1) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}