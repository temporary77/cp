#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[1001];
vector<tuple<int,int,int>> vctr;
//unordered_map<int,pair<int,int>> mp;

int main() {
	int n, x;
	scanf("%d%d",&n,&x);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i].first);
		arr[i].second = i;
		for (int j = i-1; j > 0; --j) {
			vctr.push_back({arr[i].first+arr[j].first,i,j});
		}
	}
	sort(vctr.begin(),vctr.end());
	/*for (auto it : vctr) {
		printf("{%d,%d,%d}\n",get<0>(it),get<1>(it),get<2>(it));
	}*/
	int a, b, c, d;
	int suml, sumr;
	int l = 0;
	int r = vctr.size()-1;
	for (;l < r;) {
		suml = get<0>(vctr[l]);
		sumr = get<0>(vctr[r]);
		if (suml+sumr > x) {
			--r;
		} else if (suml+sumr < x) {
			++l;
		} else {
			a = get<1>(vctr[l]);
			b = get<2>(vctr[l]);
			c = get<1>(vctr[r]);
			d = get<2>(vctr[r]);
			if (a != c && b != c && a != d && b != d) {
				printf("%d %d %d %d",a,b,c,d);
				return 0;
			}
			++l;
			--r;
			/*if (get<0>(vctr[l+1])-suml <= sumr-get<0>(vctr[r-1])) {
				++l;
			} else {
				--r;
			}*/
		}
	}
	printf("IMPOSSIBLE");
	return 0;
}