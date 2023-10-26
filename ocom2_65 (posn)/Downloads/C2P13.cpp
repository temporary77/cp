#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("test_input.txt","r",stdin);
	string word = "";
	char c;
	map<string,int> mp;
	for (;;) {
		scanf("%c",&c);
		if (!ispunct(c) && c != ' ' && c != '\n') {
			word.push_back(tolower(c));
		} else if (c == ' ') {
			++mp[word];
			word = "";
		} else if (c == '\n') {
			break;
		}
	}
	++mp[word];
	for (auto it : mp) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}