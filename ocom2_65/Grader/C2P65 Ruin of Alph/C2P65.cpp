#include <bits/stdc++.h>
using namespace std;

int arr[1024][1024];

void recursion(int x, int y, int a, int b, int n) {
	if (n == 2) {
		if (a == 0) {
			if (b == 0) {
				arr[x+1][y+1] = 4;
				arr[x+1][y] = 4;
				arr[x][y+1] = 4;
			} else {
				arr[x+1][y+1] = 3;
				arr[x+1][y] = 3;
				arr[x][y] = 3;
			}
		} else {
			if (b == 0) {
				arr[x+1][y+1] = 2;
				arr[x][y] = 2;
				arr[x][y+1] = 2;
			} else {
				arr[x][y+1] = 1;
				arr[x+1][y] = 1;
				arr[x][y] = 1;
			}
		}
		return;
	}
	int nn = n/2;
	if (a < nn && b < nn) {
		recursion(x,y,a,b,nn);
		recursion(x,y+nn,nn-1,0,nn);
		recursion(x+nn,y,0,nn-1,nn);
		recursion(x+nn,y+n/2,0,0,nn);
		recursion(x+nn-1,y+nn-1,0,0,2);
	} else if (a < nn && b >= nn) {
		recursion(x,y,nn-1,nn-1,nn);
		recursion(x,y+nn,a,b-nn,nn);
		recursion(x+nn,y,0,nn-1,nn);
		recursion(x+nn,y+nn,0,0,nn);
		recursion(x+nn-1,y+nn-1,0,1,2);
	} else if (a >= nn && b < nn) {
		recursion(x,y,nn-1,nn-1,nn);
		recursion(x,y+nn,nn-1,0,nn);
		recursion(x+nn,y,a-nn,b,nn);
		recursion(x+nn,y+nn,0,0,nn);
		recursion(x+nn-1,y+nn-1,1,0,2);
	} else if (a >= nn && b >= nn) {
		recursion(x,y,nn-1,nn-1,nn);
		recursion(x,y+nn,nn-1,0,nn);
		recursion(x+nn,y,0,nn-1,nn);
		recursion(x+nn,y+nn,a-nn,b-nn,nn);
		recursion(x+nn-1,y+nn-1,1,1,2);
	}
	return;
}

int main() {
	int n;
	scanf("%d",&n);
	n = pow(2,n);
	int a, b;
	scanf(" %*c%d %*c%d %*c",&a,&b);
	recursion(0,0,--a,--b,n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}