#include <bits/stdc++.h>
using namespace std;
 
pair<int,int> arr[20];
int ans[21];
int n;
 
void recursion(int i, int max1, int cnt) {
	if (i == n) {
		return;
	}
	//printf("%d %d %d %d\n",i,min1,max1,cnt);
	if (arr[i].second <= max1) {
		recursion(i+1,max1,cnt);
		return;
	}
	++ans[cnt+1];
	recursion(i+1,max(max1,arr[i].second),cnt+1);
	recursion(i+1,max1,cnt);
	return;
}
 
bool comp(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	} else {
		return a.first < b.first;
	}
}
 
int main() {
	int m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&arr[i].first,&arr[i].second);
	}
	sort(arr,arr+n);
	recursion(0,INT_MIN,0);
	for (int i = 0; i < m; ++i) {
		int k;
		scanf("%d",&k);
		printf("%d\n",ans[k]);
	}
	return 0;
}