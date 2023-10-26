#include <bits/stdc++.h>
using namespace std;

int main() {
	long long seed = 821;
	long long multi = (long long)pow(seed,rand())%LLONG_MAX;
	if (multi < 0) {
		multi += LLONG_MAX;
	}
	for (int a = 0; a < 1000; ++a) {
		printf("%d <<<<<<<<<<\n",a);
		++seed;
		int n = 5;
		printf("%d\n",n);
		// vector<int> vctr = {1,1,1,2,2,2,3,3,3};
		// for (int i = 0; i < 1000; ++i) {
		// 	random_shuffle(vctr.begin(),vctr.end());
		// 	for (auto it : vctr) {
		// 		printf("%d ",it);
		// 	}
		// 	printf("\n");
		// }
		// printf("10000 10000 100000000\n");
		int arr[n+1];
		for (int i = 0; i < n; ++i) {
			int a = (rand()*seed)%500+1;
			int b = (rand()*seed)%500;
			int c = (rand()*seed)%100+1;
			arr[i] = (rand()*seed)%n;
			printf("%d %d %d %d\n",a,a+b,c,arr[i]);
		}
		for (int i = 0; i < n; ++i) {
			int e = (rand()*seed)%(n-arr[i]);
			printf("%d ",arr[i]+e);
			for (int j = 0; j < arr[i]+e; ++j) {
				printf("%d ",(rand()*seed)%n);
			}
			printf("\n");
		}
	}
	return 0;
	for (int t = 0; t < 1000; ++t) {
		int n = rand()%1000+1001;
		printf("%d\n",n);
		for (long long i = 0; i < n; ++i) {
			printf("%d ",rand()%2000+1);
		}
		printf("\n");
		// for (long long i = 0; i < 10000; ++i) {
		// 	int d = rand()%2;
		// 	if (d) {
		// 		int a = rand()%10000;
		// 		int b = rand()%10000;
		// 		int c = rand()%100000001;
		// 		printf("2 %d %d %d\n",a,b,c);
		// 	} else {
		// 		printf("1 %d\n",rand()%10000);
		// 	}
		// }
	}

	return 0;
}