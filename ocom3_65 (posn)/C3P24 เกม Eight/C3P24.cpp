#include <bits/stdc++.h>
using namespace std;

unordered_map<string,string> mp;
queue<pair<string,string>> que;

int main() {
	int n;
	scanf("%d",&n);
	que.push({"12345678x",""});
	mp["12345678x"] = "";
	for (;!que.empty();) {
		string str = que.front().first;
		string str2 = que.front().second;
		que.pop();
		int x = str.find('x');
		if (x >= 3) {
			swap(str[x],str[x-3]);
			if (mp.find(str) == mp.end()) {
				que.push({str,str2+'d'});
				mp[str] = str2+'d';
			}
			swap(str[x],str[x-3]);
		}
		if (x <= 5) {
			swap(str[x],str[x+3]);
			if (mp.find(str) == mp.end()) {
				que.push({str,str2+'u'});
				mp[str] = str2+'u';
			}
			swap(str[x],str[x+3]);
		}
		if (x%3 != 0) {
			swap(str[x],str[x-1]);
			if (mp.find(str) == mp.end()) {
				que.push({str,str2+'r'});
				mp[str] = str2+'r';
			}
			swap(str[x],str[x-1]);
		}
		if (x%3 != 2) {
			swap(str[x],str[x+1]);
			if (mp.find(str) == mp.end()) {
				que.push({str,str2+'l'});
				mp[str] = str2+'l';
			}
			swap(str[x],str[x+1]);
		}
	}
	for (int i = 0; i < n; ++i) {
		char c;
		string str = "";
		for (int j = 0; j < 9; ++j) {
			scanf(" %c",&c);
			str += c;
		}
		if (mp.find(str) == mp.end()) {
			printf("unsolvable\n");
		} else {
			string ans = mp[str];
			reverse(ans.begin(),ans.end());
			cout << ans << "\n";
		}
	}

	return 0;
}