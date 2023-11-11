#include <bits/stdc++.h>
using namespace std;

bool wall[1001][1001];
int rcnt[1001];
int ccnt[1001];

int main() {
	cin.tie(NULL);
	int n, m;
	scanf("%d%d",&n,&m);
	string str;
	int ttl = 0;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < m; ++j) {
			if (str[j] == '*') {
				wall[i][j] = 1;
				++rcnt[i];
				++ccnt[j];
				++ttl;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (rcnt[i]+ccnt[j]-(wall[i][j] ? 1 : 0) == ttl) {
				printf("YES\n%d %d",i+1,j+1);
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}