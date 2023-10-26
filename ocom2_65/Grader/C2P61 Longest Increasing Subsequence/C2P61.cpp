#include <bits/stdc++.h>
using namespace std;

map<int,pair<int,int>> mp;
set<int,greater<int>> heights;

int main() {
	for (int a = 0; a < 100; ++a) {
	int n;
	scanf("%d",&n);
	int k;
	bool check;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		check = 0;
		for (auto it = heights.begin(); it != heights.end(); ++it) {
			if (k <= mp[*it].first && k >= mp[*it].second) {
				mp[*it].first = k;
				check = 1;
				break;
			} else if (k > mp[*it].first) {
				int nh = *it;
				mp[nh+1].first = k;
				//printf("key %d now %d\n",nh+1,k);
				mp.erase(nh);
				//printf("map2 %d\n",mp[2]);
				heights.erase(it);
				heights.insert(nh+1);
				check = 1;
				break;
			}
		}
		if (check == 0) {
			mp[1].first = k;
			mp[1].second = -1;
			heights.insert(1);
		}
		/*for (auto it : heights) {
			printf("%d ",it);
		}
		printf("\n");*/
	printf("%d %d\n",i,*(heights.begin()));
	}
	printf("%d",*(heights.begin()));
	heights.clear();
	mp.clear();
}
	return 0;
}