#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	//n = rand()%10+1;
	//m = rand()%10+1;
	//printf("%d %d\n",n,m);
	while(m > n/2) {
		n *= 2;
	}
	vector<int> arr[n];
	int c;
	for (int i = 0; i < m; ++i) {
		scanf("%d",&c);
		//c = rand()%100+1;
		arr[c%n].push_back(c);
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i].empty()) {
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
