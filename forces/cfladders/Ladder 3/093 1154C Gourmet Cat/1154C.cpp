#include <bits/stdc++.h>
using namespace std;

int week[7] = {0,1,2,0,2,1,0};
int arr[3];

int main() {
	int a, b, c;
	scanf("%d%d%d",&a,&b,&c);
	int ans = 0;
	int cur;
	for (int i = 0; i < 7; ++i) {
		cur = 0;
		arr[0] = a; arr[1] = b; arr[2] = c;
		for (int j = i; j < 7; ++j) {
			if (arr[week[j]] == 0) {
				ans = max(ans,cur);
				break;
			}
			++cur;
			--arr[week[j]];
		}
		if (arr[0] < 0 || arr[1] < 0 || arr[2] < 0)continue;
		int idx = min(arr[0]/3,min(arr[1]/2,arr[2]/2));
		cur += idx*7;
		arr[0] -= idx*3;
		arr[1] -= idx*2;
		arr[2] -= idx*2;
		for (int j = 0; j < 7; ++j) {
			if (arr[week[j]] == 0)break;
			++cur;
			--arr[week[j]];
		}
		ans = max(ans,cur);
	}
	printf("%d",ans);
	return 0;
}