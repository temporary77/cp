#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, n;
	scanf("%d%d%d",&a,&b,&n);
	string str = to_string(a);
	for (int i = 0; i < n; ++i) {
		int x = b-((10*a+b-1)%b+1);
		if (x >= 10) {
			printf("-1");
			return 0;
		}
		a = (10*a+x)%b;
		str.push_back(x+'0');
	}
	cout << str;
	return 0;
}