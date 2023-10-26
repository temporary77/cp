#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	char c;
    int id, f, p, l;
    string name;
	set<pair<int,string>> st;
	map<int,vector<string>> mp;
	for (int i = 0; i < n; ++i) {
		scanf(" %c",&c);
		if (c == 'A') {
			scanf("%d",&id);
			cin >> name;
			st.insert({id,name});
		} else if (c == 'M') {
			scanf("%d%d",&f,&p);
			for (int j = p; j < p+f; ++j) {
				mp[j].push_back(st.begin()->second);
				st.erase(st.begin());
			}
		} else if (c == 'R') {
			scanf("%d",&l);
			mp[l].clear();
		}
	}
	set<string> outcasts;
	for (auto it : st) {
		outcasts.insert(it.second);
	}
	for (auto it : mp) {
		if ((it.second).empty())continue;
		for (auto it2 = (it.second).begin(); it2 != (it.second).end(); ++it2) {
			outcasts.insert(*it2);
		}
	}
	for (auto it : outcasts) {
		cout << it << endl;
	}
	return 0;
}
