#include <bits/stdc++.h>
using namespace std;

bool wall[1001][1001];

int main() {
	cin.tie(NULL);
	int n, m;
	scanf("%d%d",&n,&m);
	int r1 = -1;
	int r2 = -1;
	int c1 = -1;
	int c2 = -1;
	int rf = -1;
	int cf = -1;
	string str;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < m; ++j) {
			if (str[j] == '*') {
				// printf("%d %d\n%d %d\n%d %d\n%d %d\n-----\n",i,j,r1,c1,r2,c2,rf,cf);
				bool rcheck = 1;
				bool ccheck = 1;
				if (i == rf)goto g;
				if (r1 == -1) {
					r1 = i;
				} else if (r2 == -1) {
					if (r1 == i && rf == -1) {
						rf = r1;
						r2 = -1;
					} else {
						if (rf != -1 && i != rf) {
							rcheck = 0;
						} else {
							r2 = i;
						}
					}
				} else if (r1 != -1 && r2 != -1) {
					if (i != r1 && i != r2) {
						if (c2 == -1) {
							if (j != cf) {
								rf = i;
								r2 = -1;
								r1 = i;
							}
						} else {
							rcheck = 0;
						}
					} else {
						if (i == r1)rf = r1;
						else rf = r2;
						r1 = rf;
						r2 = -1;
						if (c2 != -1) {
							if (wall[rf][c1]) {
								cf = c2;
								c1 = cf;
								c2 = -1;
							} else {
								cf = c1;
								c2 = -1;
							}
						}
					}
				}
				g:;
				if (j == cf)goto h;
				if (c1 == -1) {
					c1 = j;
				} else if (c2 == -1) {
					if (c1 == j && cf == -1) {
						cf = c1;
						c2 = -1;
					} else {
						if (cf != -1 && j != cf) {
							ccheck = 0;
						} else {
							c2 = j;
						}
					}
				} else if (c1 != -1 && c2 != -1) {
					if (j != c1 && j != c2) {
						if (r2 == -1) {
							if (i != rf) {
								cf = j;
								c1 = cf;
								c2 = -1;
							}
						} else {
							ccheck = 0;
						}
					} else {
						if (j == c1)cf = c1;
						else cf = c2;
						c1 = cf;
						c2 = -1;
						if (r2 != -1) {
							if (wall[r1][cf]) {
								rf = r2;
								r1 = rf;
								r2 = -1;
							} else {
								rf = r1;
								r2 = -1;
							}
						}
					}
				}
				h:;
				if (!rcheck && !ccheck) {
					printf("NO");
					return 0;
				}
				wall[i][j] = 1;
			}
		}
	}
	if (rf == -1) {
		if (r1 == -1) {
			rf = 0;
		} else if (r2 == -1) {
			rf = r1;
		} else {
			cf = c1;
			if (wall[r1][c1]) {
				rf = r2;
			} else {
				rf = r1;
			}
		}
	}
	if (cf == -1) {
		if (c1 == -1) {
			cf = 0;
		} else if (c2 == -1) {
			cf = c1;
		} else {
			if (wall[r1][c1]) {
				cf = c2;
			} else {
				cf = c1;
			}
		}
	}
	printf("YES\n%d %d",rf+1,cf+1);
	return 0;
}