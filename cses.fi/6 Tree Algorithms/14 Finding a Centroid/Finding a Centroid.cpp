#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
int hchild[200001];
int size1[200001];
int n;

int findsize(int node, int pa) {
	int sz = 1;
	int max1 = -1, heavychild = -1;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		int csz = findsize(it,node);
		sz += csz;
		if (csz > max1) {
			max1 = csz;
			heavychild = it;
		}
	}
	hchild[node] = heavychild;
	size1[node] = sz;
	return sz;
}

int findcentroid(int node, int behind) {
	if (behind <= n/2 && size1[hchild[node]] <= n/2) {
		return node;
	} else {
		return findcentroid(hchild[node],size1[node]-size1[hchild[node]]);
	}
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	findsize(1,-1);
	printf("%d",findcentroid(1,0));
	return 0;
}