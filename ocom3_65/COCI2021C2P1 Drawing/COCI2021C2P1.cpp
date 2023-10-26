#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[101];

/*
	
_/  _  __
     \  

 / /\   _
/      /

\/  \  \_ 
     \  

*/
int main() {
	cin.tie(nullptr);
	//for (int t = 0; t < 100; ++t) {
	int n;
	scanf("%d",&n);
	string str;
	cin >> str;
	int a = 0, b = 0, c = 0;
	int cnt = 0, state = 2;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '+') {
			if (state == 1) {
				++c;
				a = max(a,c);
				++cnt;		
			}
			state = 1;
		} else if (str[i] == '-') {
			if (state <= 0) {
				--c;
				b = min(b,c);
				--cnt;
			}
			state = -1;
		} else {
			if (state == 1) {
				++c;
				a = max(a,c);
				++cnt;		
			}
			state = 0;
		}
		arr[i] = {cnt,state};
		//printf("%d %d %d\n",a,b,c);
	}
	for (int i = a; i >= b; --i) {
		for (int j = 0; j < n; ++j) {
			if (arr[j].first == i) {
				if (arr[j].second == 1)printf("/");
				else if (arr[j].second == 0)printf("_");
				else if (arr[j].second == -1)printf("\\");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
	//}
	return 0;
}