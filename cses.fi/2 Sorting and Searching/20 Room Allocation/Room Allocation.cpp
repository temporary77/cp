#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<tuple<int,bool,int>, vector<tuple<int,bool,int>>, greater<tuple<int,bool,int>>> pq3;
int ans[200002];
int max1 = 0;
int n;
int a, b, idx;
bool d;

int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&a,&b);
		pq3.push({a,0,i});
		pq3.push({b,1,i});
		pq.push(i+1);
	}
	for (;!pq3.empty();) {
		if (!get<1>(pq3.top())) {
			ans[get<2>(pq3.top())] = pq.top();
			max1 = max(max1,pq.top());
			pq.pop();
		} else {
			pq.push(ans[get<2>(pq3.top())]);
		}
		pq3.pop();
	}
	printf("%d\n",max1);
	for (int i = 0; i < n; ++i) {
		printf("%d ",ans[i]);
	}
	//printf("d");
	return 0;
}