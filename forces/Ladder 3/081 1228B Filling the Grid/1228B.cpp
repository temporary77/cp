#include <bits/stdc++.h>
using namespace std;

int hrr[1001];
int wrr[1001];
const int mod = 1e9+7;

int main() {
	int h, w;
	scanf("%d%d",&h,&w);
	for (int i = 0; i < h; ++i) {
		scanf("%d",&hrr[i]);
	}
	for (int j = 0; j < w; ++j) {
		scanf("%d",&wrr[j]);
	}
	long long free = 1;
	int hd, wd;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (i < wrr[j]) {
				hd = 1;
			} else if (i == wrr[j]) {
				hd = 2;
			} else {
				hd = 0;
			}
			if (j < hrr[i]) {
				wd = 1;
			} else if (j == hrr[i]) {
				wd = 2;
			} else {
				wd = 0;
			}
			if (hd > 0 && wd > 0 && hd != wd) {
				printf("0");
				return 0;
			} else if (!hd && !wd) {
				free <<= 1;
				free %= mod;
			}
		}
	}
	printf("%lld",free);
	return 0;
}