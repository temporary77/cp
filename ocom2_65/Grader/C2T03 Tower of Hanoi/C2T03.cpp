#include <bits/stdc++.h>
using namespace std;

vector<int> at[3];
int nm;

void real() {
	for (int i = nm-1; i >= 0; --i) {
		for (int j = 0; j < 3; ++j) {
			if (j > 0)printf("%c",46);
			int det;
			if (at[j].size() <= i) {
				det = 0;
			} else {
				det = at[j][i];
			}
			for (int k = -1*nm+1; k <= nm-1; ++k) {
				if (abs(k)+1 <= det) {
					printf("%c",61);
				} else if (k == 0) {
					printf("%c",124);
				} else {
					printf("%c",46);
				}
			}
		}
		printf("\n");
	}
	for (int i = -2; i < (nm*2-1)*3; ++i) {
		printf("%c",45);
	}
	printf("\n");
}

void recursion(int n, int a, int c) {
	if (n == 1) {
		at[c].push_back(at[a].back());
		at[a].pop_back();
		real();
		//printf("%c %c\n",65+a,65+c);
		return;
	}
	recursion(n-1,a,3-a-c);
	recursion(1,a,c);
	recursion(n-1,3-a-c,c);
	return;
}

int main() {
	scanf("%d",&nm);
	for (int i = nm; i > 0; --i) {
		at[0].push_back(i);
	}
	//real();
	recursion(nm,0,2);
	return 0;
}