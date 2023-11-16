#include <bits/stdc++.h>
using namespace std;

int state[1000001];
vector<int> left1;
vector<int> vctr;

int main() {
	int n;
	scanf("%d",&n);
	int cur = 0;
	int k;
	int d = 0;
	for (int i = 0; i < n; ++i) {
		++d;
		scanf("%d",&k);
		if (k > 0) {
			if (state[k]) {
				printf("-1");
				return 0;
			}
			state[k] = 1;
			++cur;
		} else if (k < 0) {
			k *= -1;
			if (state[k] == 0 || state[k] == 2) {
				printf("-1");
				return 0;
			}
			state[k] = 2;
			left1.push_back(k);
			--cur;
			if (cur == 0) {
				vctr.push_back(d);
				d = 0;
				for (auto it : left1)state[it] = 0;
				left1.clear();
			}
		}
	}
	if (cur != 0) {
		printf("-1");
		return 0;
	}
	printf("%d\n",vctr.size());
	for (auto it : vctr) {
		printf("%d ",it);
	}
	return 0;
}