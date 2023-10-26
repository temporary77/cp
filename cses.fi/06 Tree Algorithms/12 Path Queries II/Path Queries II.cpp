#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> graph[200001];
int arr[200001];
int chain[200001];
int height[200001];
int bl[200001][18];
// int hchild[200001];
int treeidx[200001];
int chainval[200001];
int size1[200001];
 
struct smtree {
	int tree[800001];
 
	void build(int n, int a, int b) {
		if (a > b) {
			return;
		}
		if (a == b) {
			tree[n] = chainval[a];
			return;
		}
		build(2*n,a,(a+b)/2);
		build(2*n+1,(a+b)/2+1,b);
		tree[n] = max(tree[2*n],tree[2*n+1]);
		return;
	}
 
	void update(int n, int a, int b, int x, int val) {
		if (a > b || x < a || b < x) {
			return;
		}
		if (x <= a && b <= x) {
			tree[n] = val;
			return;
		}
		update(2*n,a,(a+b)/2,x,val);
		update(2*n+1,(a+b)/2+1,b,x,val);
		tree[n] = max(tree[2*n],tree[2*n+1]);
		return;
	}
 
	int query(int n, int a, int b, int x, int y) {
		if (a > b || b < x || y < a) {
			return INT_MIN;
		}
		if (x <= a && b <= y) {
			return tree[n];
		}
		return max(query(2*n,a,(a+b)/2,x,y),query(2*n+1,(a+b)/2+1,b,x,y));
	}
} tree1;
 
int findsize(int node, int pa, int h) {
	height[node] = h;
	if (pa != -1) {
		bl[node][0] = pa;
	}
	int sz = 0;
	int max1 = INT_MIN;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		sz += findsize(it,node,h+1);
	}
	size1[node] = sz+1;
	return sz+1;
}
 
 
int timer = 0;
void precompute(int node, int pa, int topc) {
	chain[node] = topc;
	treeidx[node] = timer;
	chainval[timer] = arr[node];
	++timer;
	int max1 = INT_MIN, heavychild = -1;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		if (size1[it] > max1) {
			max1 = size1[it];
			heavychild = it;
		}
	}
	// hchild[node] = heavychild;
	if (heavychild == -1)return;
	precompute(heavychild,node,topc);
	for (auto it : graph[node]) {
		if (it == pa || it == heavychild)continue;
		precompute(it,node,it);
	}
	return;
}
 
int findlca(int a, int b) {
	if (height[a] != height[b]) {
		if (height[b] < height[a]) {
			swap(a,b);
		}
		for (int dist = height[b]-height[a]; dist > 0; dist -= dist&-dist) {
			b = bl[b][(int)log2(dist&-dist)];
		}
	}
	int cap1 = floor(log2(n));
	for (;a != b;) {
		int l = -1;
		int r = cap1;
		for (;;) {
			if (l >= r)break;
			int m = (l+r+1)/2;
			if (bl[a][m] == bl[b][m]) {
				r = m-1;
			} else {
				l = m;
			}
		}
		if (l == -1) {
			l = 0;
		}
		a = bl[a][l];
		b = bl[b][l];
		cap1 = l-1;
	}
	return a;
}
 
int maxpath(int x, int y) {
	int ans = INT_MIN;
	// printf("\n%d <<\n",lca);
	for (;chain[x] != chain[y];) {
		if (chain[x] == x) {
			ans = max(ans,arr[x]);
			x = bl[x][0];
		} else {
			ans = max(ans,tree1.query(1,0,n-1,treeidx[chain[x]],treeidx[x]));
			x = bl[chain[x]][0];
		}
	}
	ans = max(ans,tree1.query(1,0,n-1,treeidx[y],treeidx[x]));
	return ans;
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
	findsize(1,-1,0);
	precompute(1,-1,1);
	// for (int i = 1; i <= n; ++i) {
	// 	printf("%d ",chain[i]);
	// }
	// printf("\n");
	tree1.build(1,0,n-1);
	for (int k = 1; k <= floor(log2(n)); ++k) {
		for (int i = 1; i <= n; ++i) {
			bl[i][k] = bl[bl[i][k-1]][k-1];
		}
	}
	for (int i = 0; i < q; ++i) {
		int k;
		scanf("%d",&k);
		if (k == 1) {
			int s, x;
			scanf("%d%d",&s,&x);
			tree1.update(1,0,n-1,treeidx[s],x);
			arr[s] = x;
		} else if (k == 2) {
			int a, b;
			scanf("%d%d",&a,&b);
			int lca = findlca(a,b);
			int ans = INT_MIN;
			printf("%d ",max(max(ans,maxpath(a,lca)),maxpath(b,lca)));
		}
	}
	return 0;
}