#include <bits/stdc++.h>
using namespace std;

unordered_map<double,vector<int>> mp;
int arr[200001];

int main() {
	int n;
	scanf("%d",&n);
	int a, b, c;
	for (int i = 0; i < n; ++i) {
		scanf(" %*c%d%*c%d%*c%*c%d%*c",&a,&b,&c);
		mp[(double)(a+b)/c].push_back(i);
	}
	for (auto it : mp) {
		for (auto it2 : it.second) {
			arr[it2] = it.second.size();
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ",arr[i]);
	}
	return 0;
}