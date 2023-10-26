#include <bits/stdc++.h>
using namespace std;

int arr[3];

int main() {
	cin.tie(NULL);
	for (int i = 0; i < 3; ++i) {
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+3);
	string str;
	cin >> str;
	for (auto c : str) {
		printf("%d ",arr[c-65]);
	}
	return 0;
}