#include <bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> mp1, mp2;

int main() {
	int n;
	scanf("%d",&n);
	int a, b;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&a,&b);
		mp1[a+b].push_back(a);
		mp2[a-b].push_back(a);
		//printf("%d %d\n",a+b,a-b);
	}
	int ans = INT_MIN;
	for (auto it : mp1) {
		sort(it.second.begin(),it.second.end());
		ans = max(ans,*it.second.rbegin()-*it.second.begin());
	}
	for (auto it : mp2) {
		sort(it.second.begin(),it.second.end());
		ans = max(ans,*it.second.rbegin()-*it.second.begin());
	}
	printf("%d",ans);
	return 0;
}