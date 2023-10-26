#include <bits/stdc++.h>
using namespace std;
 
int arr[200001];
int cnt[26];
int max1 = 0;
 
int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	int n = str.size();
	for (auto it : str) {
		++cnt[it-'A'];
		max1 = max(max1, cnt[it-'A']);
	}
	for (int i = 0; i < 26; ++i) {
		//printf("%d ",cnt[i]);
	}
	//printf("\n");
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < n; ++j) {
			--cnt[str[j]-'A'];
			str[j] = (char)(((int)str[j]-'A'+arr[j])%26+'A');
			++cnt[str[j]-'A'];
		}
		for (int j = 0; j < 26; ++j) {
			//printf("%d ",cnt[j]);
			max1 = max(max1,cnt[j]);
		}
		//printf("\n");
	}
	printf("%d",max1);
	return 0;
}