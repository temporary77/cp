#include <bits/stdc++.h>
using namespace std;

struct rnge {
	int x, y, idx;
	bool operator < (const rnge &rhs) const {
		if (x == rhs.x) {
			return y < rhs.y;
		} else {
			return x > rhs.x;
		}
	}
};

rnge arr[400001];
int pos[400001];
int mx = 0;
int ans[400001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&arr[i].x,&arr[i].y,&arr[i].idx);
		arr[i].idx = i;
	}
	sort(arr,arr+n);
	pos[0] = INT_MIN;
	for (int i = 0; i < n; ++i) {
		ans[arr[i].idx] = (upper_bound(pos,pos+mx+1,arr[i].y)-1)-pos+1;
		if (ans[arr[i].idx] > mx) {
			mx = ans[arr[i].idx];
		}
		pos[ans[arr[i].idx]] = arr[i].y;
	}
	/*for (int i = 0; i < n; ++i) { 
		printf("%d %d %d\n",arr[i]);
	}*/
	printf("%d\n",mx);
	for (int i = 0; i < n; ++i) {
		printf("%d ",ans[i]);
	}
	return 0;
}