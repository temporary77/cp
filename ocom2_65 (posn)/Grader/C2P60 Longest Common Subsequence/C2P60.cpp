#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];

int main() {
	cin.tie(nullptr);
	string str1, str2;
	cin >> str1 >> str2;
	int n = str1.length();
	int m = str2.length();
	//printf("%d %d\n",n,m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (str1[i-1] == str2[j-1]) {
				arr[i][j] = arr[i-1][j-1]+1;
			} else {
				arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
			}
		}
	}
	/*for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			printf("%02d ",arr[i][j]);
		}
		printf("\n");
	}*/
	printf("%d",arr[n][m]);
	return 0;
}
// same last digit; (n,m) = (n-1,m-1)+1;
// not same; (n,m) = max (n-1,m) and (n,m-1);

/*  a  a  a  a
00 00 00 00 00 
a 00 01 01 01 01 
a 00 01 02 02 02 
b 00 01 02 02 02 
a 00 01 02 03 03 
*/