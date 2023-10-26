#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		int k;
		vector<int> vctr;
		int x, a;
		for (int i = 0; i < m; ++i) {
			scanf("%d",&k);
			x = 0;
			for (int j = 0; j < k; ++j) {
				scanf("%d",&a);
				x += pow(2,a);
			}
			vctr.push_back(x);
			//printf("%d <\n",x);
		}
		unordered_map<int,int> mp;
		vector<int> vctr2;
		vctr2.push_back(0);
		mp[0] = 0;
		for (auto it : vctr) {
			//printf("THE %d\n",it);
			for (int i = vctr2.size()-1; i >= 0; --i) {
				//printf("RA %d\n",vctr2[i]);
				if (mp.find(vctr2[i]^it) == mp.end()) {
					//printf("CK %d\n",vctr2[i]^it);
					mp[vctr2[i]^it] = mp[vctr2[i]]+1;
					vctr2.push_back(vctr2[i]^it);
				} else {
					mp[vctr2[i]^it] = min(mp[vctr2[i]^it],mp[vctr2[i]]+1);
				}
			}
			/*for (auto it2 : mp) {
				printf("%d - %d\n",it2);
			}
			printf("\n");*/
		}
		int q;
		scanf("%d",&q);
		string str;
		printf("Case %d:\n",ti+1);
		for (int i = 0; i < q; ++i) {
			cin >> str;
			int query = 0;
			for (int j = n-1; j >= 0; --j) {
				if (j == n-1)query += str[j]-48;
				else query += pow(((str[j]-48)*2),n-1-j);
			}
			if (mp.find(query) == mp.end())printf("-1\n");
			else printf("%d\n",mp[query]);
		}
	}

	return 0;
}