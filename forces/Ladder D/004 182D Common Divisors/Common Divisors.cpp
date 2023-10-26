#include <bits/stdc++.h>
using namespace std;

set<int> st, st2, st3;

int main() {
	cin.tie(nullptr);
	string str1, str2;
	cin >> str1 >> str2;
	if (str1.size() > str2.size()) {
		swap(str1,str2);
	}
	for (int i = 1; i <= str1.size(); ++i) {
		if (str1.size()%i == 0) {
			for (int j = 0; j < str1.size(); ++j) {
				if (str1[j] != str1[j%i]) {
					break;
				}
				if (j == str1.size()-1) {
					st.insert(i);
				}
			}
		}
	}
	for (int i = 1; i <= str2.size(); ++i) {
		if (str2.size()%i == 0) {
			for (int j = 0; j < str2.size(); ++j) {
				if (str2[j] != str2[j%i]) {
					break;
				}
				if (j == str2.size()-1) {
					st2.insert(i);
				}
			}
		}
	}
	int cnt = 0;
	set_intersection(st.begin(),st.end(),st2.begin(),st2.end(),inserter(st3,st3.begin()));
	for (auto it : st3) {
		if (str1.substr(0,it) == str2.substr(0,it)) {
			++cnt;
		}
	}
	printf("%d",cnt);
	return 0;
}