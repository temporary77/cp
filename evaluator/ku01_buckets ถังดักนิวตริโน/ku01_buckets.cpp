#include <bits/stdc++.h>
using namespace std;

tuple<int,bool,int> arr[1001];
int valid[1001];
stack<pair<int,int>> stck;
vector<int> vctr;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&get<0>(arr[2*i]),&get<0>(arr[2*i+1]));
		get<1>(arr[2*i]) = 0;
		get<1>(arr[2*i+1]) = 1;
		get<2>(arr[2*i]) = i+1;
		get<2>(arr[2*i+1]) = i+1;
	}
	int k;
	for (int i = 0; i < m; ++i) {
		scanf("%d",&k);
		valid[k] = 1;
	}
	sort(arr,arr+2*n);
	int max1 = 0;
	int ans = 0;
	int cur = -1;
	stck.push({0,0});
	for (int i = 0; i < 2*n; ++i) {
		//printf("%d %d %d\n",get<0>(arr[i]),get<1>(arr[i]),get<2>(arr[i]));
		if (get<1>(arr[i]) == 0) {
			stck.push({get<2>(arr[i]),valid[get<2>(arr[i])]});
			//printf("<<< %d %d\n",stck.top());
		} else if (get<1>(arr[i]) == 1) {
			int cnt = stck.top().second;
			if (cnt > max1) {
				max1 = cnt;
				cur = stck.top().first;
			}
			stck.pop();
			stck.top().second += cnt;
			if (stck.top().first == 0) {
				if (cur != -1) {
					vctr.push_back(cur);
					//printf("%d %d\n",cur,max1);
				}
				max1 = 0;
				cur = -1;
			}
		}
		//printf("%d %d\n",stck.top());
	}
	printf("%d\n",vctr.size());
	for (auto it : vctr) {
		printf("%d ",it);
	}
	return 0;
}