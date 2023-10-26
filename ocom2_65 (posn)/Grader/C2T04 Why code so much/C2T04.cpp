#include <bits/stdc++.h>
using namespace std;

void lmao(vector<pair<int,int>> mp, int ans, int i, int root) {return;
			printf("i: %d\nr: %d\nc: ",i,root);
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			printf("%d ",it->second);
		}
		printf("\nb: ");
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			printf("%d ",it->first);
		}
		printf("\na: %d\n---\n",ans);
	return;
}

int main() {
	//freopen("test_input2.txt","r",stdin);
	//for (int real = 0; real < 11; ++real){
	int n;
	scanf("%d",&n);
	int arr[n];
	scanf("%d",&arr[0]);
	int root = arr[0];
	vector<pair<int,int>> mp;
	int ans = 0;
	int curmax = 0;
	for (int i = 1; i < n; ++i) {
		scanf("%d",&arr[i]);
		//printf("%d ",arr[i]);
		if (arr[i] <= root) {
			root = arr[i];
			for (auto it = mp.begin(); it != mp.end(); ++it) {
				ans = max(ans,it->second);
			}
			mp.clear();
			lmao(mp,ans,arr[i],root);
			continue;
		}
		if (arr[i] > arr[i-1]) {
			mp.push_back({arr[i-1],1});
			lmao(mp,ans,arr[i],root);
			continue;
		}
		auto it = mp.rbegin();
		for (; it != mp.rend(); ++it) {
			if (arr[i] > it->first)break;
		}
		if (it == mp.rend())printf("aint no way");
		for (auto it2 = it; it2 != mp.rbegin()-1; --it2) {
			curmax = max(curmax,it2->second);
		}
		it->second = curmax+1;
		curmax = 0;
		lmao(mp,ans,arr[i],root);
	}
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		ans = max(ans,it->second);
	}
	printf("%d\n",ans);
	//}
	return 0;
}