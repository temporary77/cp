#include <bits/stdc++.h>
using namespace std;

const int sqrtA = sqrt(1e9);
bool sieve[sqrtA+1];
vector<int> primes;
set<int> st;

int main() {
	sieve[1] = true;
	for (long long i = 2; i <= sqrtA; ++i) {
		if (!sieve[i]) {
			primes.push_back(i);
			for (long long j = i*i; j <= sqrtA; j += i) {
				sieve[j] = true;
			}
		}
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		bool check = false;
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			if (check)continue;
			for (auto it : primes) {
				if (!(a%it)) {
					if (st.find(it) != st.end()) {
						check = true;
						goto g;
					}
					st.insert(it);
					for (;!(a%it);) {
						a /= it;
					}
				}
				if (a == 1)break;
			}
			if (a > 1) {
				if (st.find(a) != st.end()) {
					check = true;
					continue;
				}
				st.insert(a);
			}
			g:;
		}
		if (check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		st.clear();
	}
	return 0;
}