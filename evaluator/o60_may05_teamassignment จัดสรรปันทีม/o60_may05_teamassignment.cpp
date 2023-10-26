#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
	int n, u, v;
	scanf("%d%d%d",&n,&u,&v);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	int l = -1, r = 1e9+1;
	for (;;) {
		int m = (l+r+1)/2;
		//printf("%d %d\n",l,r);
		deque<int> dq;
		dq.push_back(0);
		int idx = -1;
		if (l == r)break;
		for (int i = 0; i < n; ++i) {
			if (arr[i] >= m)idx = i;
			//printf("->%d %d\n",i,idx);
			for (;i-dq.front()+1 > v;) {
				//printf("-%d\n",dq.front());
				dq.pop_front();
				if (dq.empty())break;
			}
			if (dq.empty()) {
				break;
			}
			if (dq.front() <= idx && i-dq.front()+1 >= u) {
				//printf("+%d\n",i+1);
				dq.push_back(i+1);
			}
		}
		if (dq.empty()) {
			r = m-1;
		} else if (dq.back() != n) {
			r = m-1;
		} else {
			l = m;
		}
	}
	printf("%d",l);
	return 0;
}