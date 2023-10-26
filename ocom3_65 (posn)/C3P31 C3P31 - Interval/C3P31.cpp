#include <bits/stdc++.h>
using namespace std;

int arrr[26], brrr[26];

int ans = 0;
int n, m;
string str1, str2;
int t = 0;

void recursion(int k, int ansa, int ansb, int arr[], int brr[]) {
	++t;
	if ((ansa >= 0 && ansa < ans) || (ansb >= 0 && ansb < ans))return;
	printf("%d %d %d <<<<<<<<<<<<<<<<<<<\n",k,ansa,ansb);
	for (int i = 0; i < 26; ++i) {
		if (arr[i] != 0) {
			printf("{%c,%d},",i+97,arr[i]);
		}
	}
	printf("\n\n");
	for (int i = 0; i < 26; ++i) {
		if (brr[i] != 0) {
			printf("{%c,%d},",i+97,brr[i]);
		}
	}
	printf("\n");
	if (t >= 100)return;
	if (k == 0) {
		int asndr[26] = {0};
		int la = 0;
		for (int i = 0; i <= n; ++i) {
			if (i == n) {
				if (i-la == ansb) {
					printf("=== %d %d %d %d %d %d ===\n",i,la,ansb,ansa,ansb,k);
					ans = max(ans,ansb);
				} else {
					printf("-> %d %d\n",i,la);
					recursion(1,i-la,ansb,asndr,brr);
				}
			} else if (asndr[str1[i]-97] == brr[str1[i]-97]) {
				++asndr[str1[i]-97];
				if (i-la == ansb) {
					printf("=== %d %d %d %d %d %d ===\n",i,la,ansb,ansa,ansb,k);
					ans = max(ans,ansb);
				} else {
					printf("-> %d %d\n",i,la);
					recursion(1,i-la,ansb,asndr,brr);
				}
				for (;la <= i; ++la) {
					if (asndr[str1[la]-97] > brr[str1[la]-97]) {
						--asndr[str1[la]-97];
						++la;
						break;
					} else {
						--asndr[str1[la]-97];
					}
				}
			} else {
				++asndr[str1[i]-97];
			}
		}
	} else if (k == 1) {
		int bsndr[26] = {0};
		int lb = 0;
		for (int i = 0; i <= m; ++i) {
			if (i == m) {
				if (i-lb == ansa) {
					printf("=== %d %d %d %d %d %d ===\n",i,lb,ansa,ansa,ansb,k);
					ans = max(ans,ansa);
				} else {
					printf("-> %d %d\n",i,lb);
					recursion(0,ansa,i-lb,arr,bsndr);
				}
			} else if (bsndr[str2[i]-97] == arr[str2[i]-97]) {
				++bsndr[str2[i]-97]; 
				if (i-lb == ansa) {
					printf("=== %d %d %d %d %d %d ===\n",i,lb,ansa,ansa,ansb,k);
					ans = max(ans,ansa);
				} else {
					printf("-> %d %d\n",i,lb);
					recursion(0,ansa,i-lb,arr,bsndr);
				}
				for (;lb <= i; ++lb) {
					printf("-> %d %d\n",i,lb);
					if (bsndr[str2[lb]-97] > arr[str2[lb]-97]) {
						--bsndr[str2[lb]-97];
						++lb;
						break;
					} else {
						--bsndr[str2[lb]-97];
					}
				}
			} else {
				++bsndr[str2[i]-97];
			}
		}		
	}
	printf(">>>>>>>>>>>>>>>>\n");
	return;
}

int main() {
	cin.tie(nullptr);
	cin >> str1 >> str2;
	printf("vv\n");
	n = str1.size();
	m = str2.size();
	for (int i = 0; i < n; ++i) {
		++arrr[str1[i]-97];
	}
	for (int i = 0; i < m; ++i) {
		++brrr[str2[i]-97];
	}
	int ansa = -1, ansb = -2;
	int ra, rb;
	int cnta, cntb;
	recursion(0,-1,-2,arrr,brrr);
	printf("%d",ans);
	return 0;
}