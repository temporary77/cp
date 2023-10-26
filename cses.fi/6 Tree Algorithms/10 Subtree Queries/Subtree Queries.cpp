#include <bits/stdc++.h>
using namespace std;

int arr[200001];
vector<int> graph[200001];
int start1[200001];
int end1[200001];
long long tme[200001];
long long tree[200001];
int n;

int timer = 1;
void eulertour(int node, int pa) {
	start1[node] = timer;
	tme[timer] = arr[node];
	++timer;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		eulertour(it,node);
	}
	end1[node] = timer;
	// printf("%d in %d out %d\n",start1[node],node,end1[node]);
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

void update(int s, int val) {
	for (int a = s; a <= n; a += a&-a) {
		tree[a] += val;
	}
	return;
}

long long query(int a, int b) {
	long long sa = 0;
	long long sb = 0;
	--a;
	--b;
	for (int i = a; i > 0; i -= i&-i) {
		sa += tree[i];
	}
	for (int i = b; i > 0; i -= i&-i) {
		sb += tree[i];
	}
	// printf("%d %d %lld %lld\n",a,b,sa,sb);
	return sb-sa;
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
	eulertour(1,-1);
	build();
	for (int i = 0; i < q; ++i) {
		int k;
		scanf("%d",&k);
		for (int i = 1; i <= n; ++i) {
			// printf("%d ",tme[i]);
		}
		// printf("\ntree\n");
		for (int i = 1; i <= n; ++i) {
			// printf("%d ",tree[i]);
		}
		// printf("\n");
		if (k == 1) {
			int s, x;
			scanf("%d%d",&s,&x);
			// printf("%lld %d %d\n",tme[start1[s]],start1[s],x-tme[start1[s]]);
			update(start1[s],x-tme[start1[s]]);
			tme[start1[s]] = x;
		} else if (k == 2) {
			int s;
			scanf("%d",&s);
			// printf("%d %d\n",start1[s],end1[s]);
			printf("%lld\n",query(start1[s],end1[s]));
		}
	}
	return 0;
}