#include <bits/stdc++.h>
using namespace std;

int dp[256][256];
int oper[3][3] = {{2,1,0},{2,1,1},{1,2,1}};
int funct[8][8];

int main() {
	cin.tie(nullptr);
	int n;
	string str;
	bool arr[3];
	for (int i = 1; i <= 7; ++i) {
		for (int j = 1; j <= 7; ++j) {
			vector<int> vctr, vctr2;
			arr[0] = 0;
			arr[1] = 0;
			arr[2] = 0;
			if (i%2 == 1)vctr.push_back(0);
			if (i%4 >= 2)vctr.push_back(1);
			if (i >= 4)vctr.push_back(2);
			if (j%2 == 1)vctr2.push_back(0);
			if (j%4 >= 2)vctr2.push_back(1);
			if (j >= 4)vctr2.push_back(2);
			for (auto it : vctr) {
				for (auto it2 : vctr2) {
					//if (i == 7 && j == 7)printf("%d %d %d\n",it,it2,oper[it][it2]);
					arr[oper[it][it2]] = 1;
				}
			}
			for (int k = 0; k < 3; ++k) {
				if (arr[k]) {
					funct[i][j] += pow(2,k);
				}
			}
			//printf("%d ",funct[i][j]);
		}
		//printf("\n");
	}
	for (int ti = 0; ti < 20; ++ti) {
		scanf("%d",&n);
		cin >> str;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				dp[i][j] = 0;
				//if (ti == 18)printf("%d %d\n",i,j);
			}
			dp[i][i] = pow(2,str[i]-48);
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < n-i; ++j) {
				for (int k = j; k < j+i; ++k) {
					//printf("%d    %d\n",dp[j][k],dp[k+1][j+i]);
					dp[j][j+i] |= funct[dp[j][k]][dp[k+1][j+i]];		
				}
			}
		}
		if (dp[0][n-1]%2 == 1) printf("yes\n");
		else printf("no\n");
	}


	return 0;
}