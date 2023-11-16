#include <bits/stdc++.h>
using namespace std;

int arr[3][3];
int perm[6][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};

int main() {
	cin.tie(NULL);
	int n;
	scanf("%d",&n);
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'R') {
			++arr[0][i%3];
		} else if (str[i] == 'G') {
			++arr[1][i%3];
		} else if (str[i] == 'B') {
			++arr[2][i%3];
		}
	}
	string str2 = "XXX";
	int min1 = INT_MAX;
	for (int i = 0; i < 6; ++i) {
		int x = n-(arr[0][perm[i][0]]+arr[1][perm[i][1]]+arr[2][perm[i][2]]);
		if (x < min1) {
			min1 = x;
			str2[perm[i][0]] = 'R';
			str2[perm[i][1]] = 'G';
			str2[perm[i][2]] = 'B';
		}
	}
	printf("%d\n",min1);
	for (int i = 0; i < n; ++i) {
		printf("%c",str2[i%3]);
	}
	return 0;
}