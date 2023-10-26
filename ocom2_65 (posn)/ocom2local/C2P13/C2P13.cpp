#include <bits/stdc++.h>
using namespace std;

string diminished(string word) {
	string returner = "";
	for (int i = 0; i < word.size(); ++i) {
		char c = word[i];
		if (ispunct(c) == 0) {
			if (isalpha(c))c = tolower(c);
			returner.push_back(c);
		}
	}
	return returner;
}

int main() {
    freopen("test_input.txt","r",stdin);
	string word = "";
	map<string,int> mp;
	while (cin >> word) {
		string key = diminished(word);
		if (key == "")continue;
		++mp[key];
	}
	for (auto it : mp) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}
