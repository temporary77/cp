#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7+1;
bool sieve[maxn];
vector<int> vctr;

void funct() {
	for (int i = 2; i < maxn; ++i) {
		if (sieve[i] == 0)vctr.push_back(i);
		//vctr.push_back(i);
		for (int j = i; j < maxn; j += i) {
			sieve[j] = 1;
		}
	}
	return;
}

int main() {
	funct();
	/*for (auto it : vctr) {
		printf("%d ",it);
	}*/
	int n;
	scanf("%d",&n);
	int a, b, c, d;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		--a; --c;
		for (auto it : vctr) {
			if (it > max(b,d))break;
			int va = 0;
			for (int i = a/it; i > 0; i /= it) {
				va += i;	
			}
			int vb = 0;
			for (int i = b/it; i > 0; i /= it) {
				vb += i;	
			}
			int vc = 0;
			for (int i = c/it; i > 0; i /= it) {
				vc += i;	
			}
			int vd = 0;
			for (int i = d/it; i > 0; i /= it) {
				vd += i;	
			}
			if (vd-vc < vb-va) {
				printf("NE\n");
				goto g;
			}
		}
		printf("DA\n");
		g:;
	}
	return 0;
}

/*

x/p^1+x/p^2+x/p^3+...x/p^n = x/p(1-(1/p)^(n+1))/(1-1/p)

*/