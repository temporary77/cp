#include <bits/stdc++.h>
using namespace std;

bool graph[100][100];
bool visited[100][100];
int dirx[8] = {-1,0,1,-1,1,-1,0,1}, diry[8] = {-1,-1,-1,0,0,1,1,1};
int n, m;
int ans;

void recursion(int a, int b) {
	++ans;
	visited[a][b] = 1;
	for (int i = 0; i < 8; ++i) {
		int ta = a+dirx[i], tb = b+diry[i];
		if (ta < 0 || ta >= n || tb < 0 || tb >= m)continue;
		if (visited[ta][tb] == 0 && graph[ta][tb] == 1)recursion(ta,tb);
	}
	return;
}

int main() {
	//freopen("test_input.txt","r",stdin);
	string str;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < m; ++j) {
			if (str[j] == 'W') {
				graph[i][j] = 1;
			}
		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d",graph[i][j]);
		}
		printf("\n");
	}*/
	int k;
	scanf("%d",&k);
	for (int i = 0; i < k; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		--a;
		--b;
		ans = 0;
		recursion(a,b);
		printf("%d\n",ans);
		memset(visited,0,10000);
	}
	return 0;
}