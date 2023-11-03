#include <bits/stdc++.h>
using namespace std;

int nxt[200001];
vector<int> tree[200001];
int cycle[200001];
int visited[200001];
int disttocycle[200001];
int cycleidx[200001];
vector<int> cyclelength = {-1};
int bl[200001][18];
int n, q;

bool cycling;
int curcycle = 1;
int curlength;
int curidx;

void findcycles(int node) {
	visited[node] = 1;
	int cc = curcycle;
	if (visited[nxt[node]] == 1) {
		cycle[nxt[node]] = curcycle;
		cycleidx[nxt[node]] = curidx;
		++curidx;
		++curlength;
		cycling = true;
	} else if (visited[nxt[node]] == 0) {
		findcycles(nxt[node]);
	}
	if (cycling) {
		if (cycle[node] == curcycle) {
			cycling = false;
			cyclelength.push_back(curlength);
			++curcycle;
		} else {
			cycle[node] = curcycle;
			cycleidx[node] = curidx;
			++curidx;
			++curlength;
		}
	}
	visited[node] = 2;
	return;
}

queue<pair<int,int>> que;

void finddisttocycle() {
	int curdist = 0;
	for (int i = 1; i <= n; ++i) {
		if (cycle[i] > 0) {
			que.push({i,-1*cycle[i]});
		}
	}
	for (;!que.empty();) {
		++curdist;
		int t = que.size();
		for (int i = 0; i < t; ++i) {
			int x, c;
			tie(x,c) = que.front();
			que.pop();
			for (auto it : tree[x]) {
				if (cycle[it] > 0)continue;
				cycle[it] = c;
				disttocycle[it] = curdist;
				que.push({it,c});
			}
		}
	}
	return;
}

int main() {
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&nxt[i]);
		bl[i][0] = nxt[i];
		tree[nxt[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			cycling = false;
			curlength = 0;
			curidx = 1;
			findcycles(i);
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	printf("%d ",cycle[i]);
	// }
	// printf("\n");
	// for (int i = 1; i <= n; ++i) {
	// 	printf("%d ",cycleidx[i]);
	// }
	// printf("\n");
	// for (int i = 1; i < cyclelength.size(); ++i) {
	// 	printf("%d ",cyclelength[i]);
	// }
	// printf("\n");
	finddisttocycle();
	// for (int i = 1; i <= n; ++i) {
	// 	printf("%d ",cycle[i]);
	// }
	// printf("\n");
	// for (int i = 1; i <= n; ++i) {
	// 	printf("%d ",disttocycle[i]);
	// }
	// printf("\n");
	for (int k = 1; k <= 17; ++k) {
		for (int i = 1; i <= n; ++i) {
			bl[i][k] = bl[bl[i][k-1]][k-1];
		}
	}
	int a, b;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d",&a,&b);
		if (abs(cycle[a]) != abs(cycle[b])) {
			printf("-1\n");
			continue;
		}
		if (cycle[a] < 0 && cycle[b] < 0) {
			if (disttocycle[a] < disttocycle[b]) {
				printf("-1\n");
				continue;
			}
			int d = disttocycle[a]-disttocycle[b];
			for (int k = 0; k <= 17; ++k) {
				if (d&(1 << k)) {
					a = bl[a][k];
				}
			}
			if (a != b) {
				printf("-1\n");
			} else {
				printf("%d\n",d);
			}
			continue;
		}
		if (cycle[a] > 0 && cycle[b] > 0) {
			if (cycleidx[a] >= cycleidx[b]) {
				printf("%d\n",cycleidx[a]-cycleidx[b]);
			} else {
				printf("%d\n",cyclelength[cycle[a]]-(cycleidx[b]-cycleidx[a]));
			}
			continue;
		}
		if (cycle[a] > 0 && cycle[b] < 0) {
			printf("-1\n");
			continue;	
		}
		if (cycle[a] < 0 && cycle[b] > 0) {
			int d = disttocycle[a];
			for (int k = 0; k <= 17; ++k) {
				if (d&(1 << k)) {
					a = bl[a][k];
				}
			}
			if (cycleidx[a] >= cycleidx[b]) {
				printf("%d\n",d+cycleidx[a]-cycleidx[b]);
			} else {
				printf("%d\n",d+cyclelength[cycle[a]]-(cycleidx[b]-cycleidx[a]));
			}
			continue;
		}
	}
	return 0;
}