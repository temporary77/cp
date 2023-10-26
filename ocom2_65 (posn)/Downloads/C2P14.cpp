#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	//n = rand()%10+1;
	//m = rand()%10+1;
	//printf("%d %d\n",n,m);
	while(m*2 > n) {
		n *= 2;
	}
	vector<int> arr[n];
	bool chck[n];
	int c;
	for (int i = 0; i < m; ++i) {
		scanf("%d",&c);
		//c = rand()%100+1;
		arr[c%n].push_back(c);
		chck[c%n] = 1;
	}
	for (int i = 0; i < n; ++i) {
		if (chck[i] == 0) {
			printf("empty\n");
			continue;
		}
		for (int j = 0; j < arr[i].size(); ++j) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}