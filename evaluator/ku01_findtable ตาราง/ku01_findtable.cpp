#include <bits/stdc++.h>
using namespace std;

double arr[1001];
double brr[1001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf",&arr[i]);
	}
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lf",&brr[i]);
		sum += brr[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			double min1 = min(arr[i],brr[j]);
			printf("%lf ",min1);
			arr[i] -= min1;
			brr[j] -= min1;
		}
		printf("\n");
	}
	return 0;
}