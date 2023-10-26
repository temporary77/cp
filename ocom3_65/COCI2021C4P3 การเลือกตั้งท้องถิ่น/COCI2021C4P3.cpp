#include <bits/stdc++.h>
using namespace std;

int arr[200001];
unordered_map<int,vector<int>> mp[200001]; //count occurrences of values with index as starting point

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		
	}

	return 0;
}

/*
5
2 2 1 2 3 4 2 2
x x
x   x
x     x
x       x
  x   x
x         x
x           x
            x x
          x   x
  x           x
x             x
*/