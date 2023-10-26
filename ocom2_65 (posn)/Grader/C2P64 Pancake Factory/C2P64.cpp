#include <bits/stdc++.h>
using namespace std;

int arr[100001];
unordered_map<int,int> mp;

int main() {
	int n;
	scanf("%d",&n);
	int m;
	int k;
	int l;
	int max1;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&m);
		l = 1;
		max1 = 1;
		mp.clear();
		for (int j = 1; j <= m; ++j) {
			scanf("%d",&k);
			if (mp[k] >= l) {
				//printf("%d %d\n",j,l);
				max1 = max(max1,j-l);
				l = mp[k]+1;
			}
			mp[k] = j;
		}
		//printf("%d %d\n",m,l);
		max1 = max(max1,m-l+1);
		printf("%d\n",max1);
	}
	return 0;
}