#include <bits/stdc++.h>
using namespace std;

int failsaves[4] = {4,9,25,49};
vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main() {
	string str;
	for (int i = 0; i < 4; ++i) {
		printf("%d\n",failsaves[i]);
		fflush(stdout);
		cin >> str;
		if (str == "yes") {
			printf("composite");
			fflush(stdout);
			return 0;
		}
	}
	int cnt = 0;
	for (auto it : primes) {
		printf("%d\n",it);
		fflush(stdout);
		cin >> str;
		if (str == "yes") {
			++cnt;
			if (cnt >= 2) {
				printf("composite");
				fflush(stdout);
				return 0;
			}
		}
	}
	printf("prime");
	fflush(stdout);
	return 0;
}