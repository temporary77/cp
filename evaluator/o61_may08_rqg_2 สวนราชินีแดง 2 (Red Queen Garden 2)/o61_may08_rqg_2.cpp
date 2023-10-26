#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int,int>> vctr;
int dx[4] = {0,1,0,1}, dy[4] = {0,0,1,1};

void recursion(int n, int a, int b, int x, int y, int c) {
	if (n == 1) {
		for (int i = 0; i < 4; ++i) {
			if (a+dx[i] == x && b+dy[i] == y) {
				vctr.push_back({i+1,c,a+1,b+1});
			}
		}
		return;
	}
	int mida = a+(1 << n-1);
	int midb = b+(1 << n-1);
	//printf(">%d %d %d %d\n",a,b,mida,midb);
	for (int i = 0; i < 4; ++i) {
		if (mida-1+dx[i] == x && midb-1+dy[i] == y) {
			//printf("%d %d %d %d\n",i+1,c,mida,midb);
			vctr.push_back({i+1,c,mida,midb});
			recursion(n-1,a,b,mida-1,midb-1,3);
			recursion(n-1,mida,b,mida,midb-1,2);
			recursion(n-1,a,midb,mida-1,midb,2);
			recursion(n-1,mida,midb,mida,midb,3);
			return;
		}
	}
	if (x < mida && y < midb) {
		vctr.push_back({1,1,mida,midb});
		recursion(n-1,a,b,x,y,3);
		recursion(n-1,mida,b,mida,midb-1,2);
		recursion(n-1,a,midb,mida-1,midb,2);
		recursion(n-1,mida,midb,mida,midb,3);		
	} else if (x >= mida && y < midb) {
		vctr.push_back({2,1,mida,midb});
		recursion(n-1,a,b,mida-1,midb-1,3);
		recursion(n-1,mida,b,x,y,2);
		recursion(n-1,a,midb,mida-1,midb,2);
		recursion(n-1,mida,midb,mida,midb,3);
	} else if (x < mida && y >= midb) {
		vctr.push_back({3,1,mida,midb});
		recursion(n-1,a,b,mida-1,midb-1,3);
		recursion(n-1,mida,b,mida,midb-1,2);
		recursion(n-1,a,midb,x,y,2);
		recursion(n-1,mida,midb,mida,midb,3);
	} else if (x >= mida && y >= midb) {
		vctr.push_back({4,1,mida,midb});
		recursion(n-1,a,b,mida-1,midb-1,3);
		recursion(n-1,mida,b,mida,midb-1,2);
		recursion(n-1,a,midb,mida-1,midb,2);
		recursion(n-1,mida,midb,x,y,3);		
	}
	return;
}

int graph[8][8];

int main() {
	int n, x, y;
	scanf("%d%d%d",&n,&x,&y);
	recursion(n,0,0,--x,--y,1);
	for (auto it : vctr) {
		int a, b, c, d;
		tie(a,b,c,d) = it;
		printf("%d %d %d %d\n",a,b,c,d);
		/*if (a == 1) {
			graph[c][d-1] = b;
			graph[c][d] = b;
			graph[c-1][d] = b;
		} else if (a == 2) {
			graph[c-1][d-1] = b;
			graph[c][d] = b;
			graph[c-1][d] = b;
		} else if (a == 3) {
			graph[c-1][d-1] = b;
			graph[c][d] = b;
			graph[c][d-1] = b;
		} else if (a == 4) {
			graph[c-1][d-1] = b;
			graph[c][d-1] = b;
			graph[c-1][d] = b;
		}*/
	}
	/*for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			printf("%d",graph[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}