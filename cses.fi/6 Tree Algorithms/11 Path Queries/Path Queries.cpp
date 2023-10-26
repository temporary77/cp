#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
int arr[200001];
long long tree[200001];
int start1[200001];
int end1[200001];
long long tme[200001];
int n;

int timer = 1;
void eulertour(int node, int pa, long long cnt) {
	start1[node] = timer;
	tme[timer] = cnt+arr[node];
	// printf("%d %d\n",node,cnt+arr[node]);
	++timer;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		eulertour(it,node,cnt+arr[node]);
	}
	end1[node] = timer;
	return;
}

void convertion() {
	for (int i = n; i >= 1; --i) {
		tme[i] = tme[i]-tme[i-1];	
	}
	return;
}

void build() {
	for (int i = 1; i <= n; ++i) {
		for (int a = i; a <= n; a += a&-a) {
			tree[a] += tme[i];
		}
	}
	return;
}

void update(int x, int val) {
	if (x == 0)return;
	for (int a = x; a <= n; a += a&-a) {
		tree[a] += val;
	}
	return;
}

long long query(int x) {
	long long res = 0;
	for (int a = x; a > 0; a -= a&-a) {
		res += tree[a];
	}
	return res;
}

int main() {
	int q;
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	eulertour(1,-1,0);
	convertion();
	build();
	for (int i = 0; i < q; ++i) {
		int k;
		scanf("%d",&k);
		// for (int ii = 1; ii <= n; ++ii) {
		// 	printf("%lld ",tme[ii]);
		// }
		// printf("\n");
		if (k == 1) {
			int s, x;
			scanf("%d%d",&s,&x);
			//printf("%d %d %lld %d\n",start1[s],end1[s],tme[start1[s]],x-arr[s]);
			update(start1[s],x-arr[s]);
			if (end1[s] <= n)update(end1[s],arr[s]-x);
			arr[s] = x;
		} else if (k == 2) {
			int s;
			scanf("%d",&s);
			printf("%lld\n",query(start1[s]));
		}
	}

	return 0;
}