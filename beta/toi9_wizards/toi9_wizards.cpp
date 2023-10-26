#include <bits/stdc++.h>
using namespace std;

pair<int,int> k;
int n;
pair<int,int> arr[4][1501];
vector<pair<pair<int,int>,pair<int,int>>> vctr, vctr2;

int main() {
	scanf("%d%d%d",&k.first,&k.second,&n);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d%d",&arr[i][j].first,&arr[i][j].second);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vctr.push_back({{k.first-arr[0][i].first-arr[1][j].first,k.second-arr[0][i].second-arr[1][j].second},{i,j}});
			vctr2.push_back({{arr[2][i].first+arr[3][j].first,arr[2][i].second+arr[3][j].second},{i,j}});
		}
	}
	sort(vctr.begin(),vctr.end());
	sort(vctr2.begin(),vctr2.end());
	/*for (auto it : vctr) {
		printf("{%d,%d,%d,%d} ",it.first.first,it.first.second,it.second.first,it.second.second);
	}
	printf("\n");
	for (auto it2 : vctr2) {
		printf("{%d,%d,%d,%d} ",it2.first.first,it2.first.second,it2.second.first,it2.second.second);
	}
	printf("\n");*/
	int it = 0, it2 = 0;
	n *= n;
	for (;it != n && it2 != n;) {
		//printf("%d %d\n",it,it2);
		if (vctr[it].first < vctr2[it2].first) {
			++it;
		} else if (vctr[it].first > vctr2[it2].first) {
			++it2;
		} else {
			printf("%d %d\n%d %d\n%d %d\n%d %d",arr[0][vctr[it].second.first].first,arr[0][vctr[it].second.first].second,arr[1][vctr[it].second.second].first,arr[1][vctr[it].second.second].second,arr[2][vctr2[it2].second.first].first,arr[2][vctr2[it2].second.first].second,arr[3][vctr2[it2].second.second].first,arr[3][vctr2[it2].second.second].second);
			return 0;
		}
	}
	return 0;
}