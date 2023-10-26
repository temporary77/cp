#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;
int mp1[501][501];
int qs[501];

int getqs(int a, int b) {
	if (a > 0)return qs[b]-qs[a-1];
	return qs[b];
}

int main() {
	int n;
	scanf("%d",&n);
	int k;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		vctr.push_back(k);
		sum += k;
		qs[i] = sum;
	}
	int idx1 = 0;
	int idx2 = n-1;
	int cnt = 0;
	for (;idx1 <= idx2;) {
		cnt += max(vctr[idx1],vctr[idx2]);
		++idx1;
		--idx2;
		}
	printf("%d\n",cnt);
	int idx3;
	int idx4;
	if (n%2 == 0) {
		for (int i = 0; i < n-1; ++i) {
			mp1[i][i+1] = max(vctr[i],vctr[i+1]);
		}
		for (int i = 3; i < n; i += 2) {
			for (int j = 0; j < n-i; ++j) {
				if (vctr[j+1] > vctr[j+i]) {
					idx1 = j+2;
					idx2 = j+i;
				} else {
					idx1 = j+1;
					idx2 = j+i-1;
				}
				if (vctr[j] > vctr[j+i-1]) {
					idx3 = j+1;
					idx4 = j+i-1;
				} else {
					idx3 = j;
					idx4 = j+i-2;
				}
				mp1[j][j+i] = max(mp1[idx1][idx2]+vctr[j],mp1[idx3][idx4]+vctr[j+i]);		
			}
		}
	} else if (n%2 == 1) {
		for (int i = 0; i < n; ++i) {
			mp1[i][i] = vctr[i];
		}
		for (int i = 2; i < n; i += 2) {
			for (int j = 0; j < n-i; ++j) {
				if (vctr[j+1] > vctr[j+i]) {
					idx1 = j+2;
					idx2 = j+i;
				} else {
					idx1 = j+1;
					idx2 = j+i-1;
				}
				if (vctr[j] > vctr[j+i-1]) {
					idx3 = j+1;
					idx4 = j+i-1;
				} else {
					idx3 = j;
					idx4 = j+i-2;
				}
				mp1[j][j+i] = max(mp1[idx1][idx2]+vctr[j],mp1[idx3][idx4]+vctr[j+i]);		
			}
		}	
	}
	printf("%d\n",mp1[0][n-1]);
	for (int i = 0; i < n-1; ++i) {
		mp1[i][i+1] = max(vctr[i],vctr[i+1]);
		mp1[i][i] = vctr[i];
	}
	mp1[n-1][n-1] = vctr[n-1];
	for (int i = 2; i < n; ++i) {
		for (int j = 0; j < n-i; ++j) {
			mp1[j][j+i] = max(vctr[j]+getqs(j+1,j+i)-mp1[j+1][j+i],vctr[j+i]+getqs(j,j+i-1)-mp1[j][j+i-1]);
		}
	}
	printf("%d",max(max(mp1[0][n-1],mp1[0][n-2]),mp1[1][n-1]));
	return 0;
}