#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	string str;
	cin >> str;
	unordered_set<string> st;
	map<char,int> mp;
	mp['P'] = 13;
	mp['K'] = 13;
	mp['H'] = 13;
	mp['T'] = 13;
	for (int i = 0; i < str.size(); i += 3) {
		char c = str[i];
		string str2 = "";
		str2 += str[i];
		str2 += str[i+1];
		str2 += str[i+2];
		if (st.find(str2) != st.end()) {
			printf("GRESKA");
			return 0;
		}
		st.insert(str2);
		//printf("%c \n",c);
		--mp[c];
	}
	printf("%d %d %d %d",mp['P'],mp['K'],mp['H'],mp['T']);
	return 0;
}