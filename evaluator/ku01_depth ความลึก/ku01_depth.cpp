#include <bits/stdc++.h>
using namespace std;

int length[50001];
int strt[50001];

bool comp(int a, int b) {
	return a > b;
}

int main() {
	int n, q;
	scanf("%d%d",&n,&q);
	int d, l;
	int depth = 0;
	int x = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&d,&l);
		if (d == 1) {
			++depth;
			strt[depth] = x;
		} else if (d == -1) {
			length[depth] = max(length[depth],x-strt[depth]);
			--depth;
		}
		x += l;
	}
	length[1] = max(length[1],x-strt[1]);
	int k;
	for (int i = 0; i < q; ++i) {
		scanf("%d",&k);
		printf("%d\n",(upper_bound(length+1,length+n+1,k,comp)-length-1));
	}
	return 0;
}