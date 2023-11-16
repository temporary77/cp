#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[200001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int ans[200001];
int cnt[200001];
queue<pair<int,int>> que;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i].first);
			arr[i].second = i;
		}
		sort(arr,arr+n);
		for (int i = 1; i <= k; ++i) {
			pq.push({0,i});
		}
		fill(ans,ans+n,0);
		fill(cnt+1,cnt+k+1,0);
		int cur = 1;
		int prev = arr[0].first;
		int idx = 0;
		for (int i = 1; i <= n; ++i) {
			if (i == n || arr[i].first != prev) {
				// printf("%d <\n",i);
				for (int j = 0; j < min(cur,k); ++j) {
					if (pq.empty())break;
					que.push(pq.top());
					pq.pop();
				}
				int q = que.size();
				for (int j = 0; j < q; ++j) {
					pair<int,int> pr = que.front();
					que.pop();
					ans[arr[j+idx].second] = pr.second;
					++pr.first;
					// printf("%d now %d\n",pr.second,pr.first);
					pq.push(pr);
				}
				if (i == n)break;
				cur = 1;
				prev = arr[i].first;
				idx = i;
			} else {
				++cur;
			}
		}
		int min1 = INT_MAX;
		for (;!pq.empty();) {
			min1 = min(min1,pq.top().first);
			pq.pop();
		}
		for (int i = 0; i < n; ++i) {
			if (cnt[ans[i]] == min1)ans[i] = 0;
			printf("%d ",ans[i]);
			++cnt[ans[i]];
		}
		printf("\n");
	}
	return 0;
}