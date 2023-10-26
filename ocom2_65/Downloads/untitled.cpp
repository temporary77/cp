#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("test_input.txt","r",stdin);
	int n, k;
	//scanf("%d%d",&n,&k);
	n = 1000, k = 1000;
	char c;	
	set<pair<int,string>> st;
	vector<string> mp[k+1];
	cout << "among" << endl;
	cout << "amongj" << endl;
	for (int i = 0; i < n; ++i) {
		//scanf(" %c",&c);
		c = rand()%3+65;
		cout << c << " ";
		if (c == 'A') {
			int id;
			string name = "";
			id = rand()%1000;
			char real = rand()%26+65;
			name.push_back(real);
			//scanf("%d",&id);
			//cin >> name;
			st.insert({id,name});
			cout << "i" << i << endl;
		} else if (c == 'B') {
			int f, p;
			//scanf("%d%d",&f,&p);
			f = rand()%500;
			p = rand()%500;
			auto it = st.begin();
			for (int j = p; j < p+f; ++j) {
				if (st.empty())break;
				mp[j].push_back((*it).second);
				st.erase(it);
			}
			cout << "i" << i << endl;
		} else if (c == 'C') {
			int l;
			//scanf("%d",&l);
			l = rand()%1000;
			cout << "i" << i << endl;
			if (mp[l].empty())continue;
			mp[l].erase(mp[l].begin());
		}
		printf("-----------------------------\n");
		for (auto it : st) {
			cout << it.first << " ";
		}
		cout << "\n";
		for (auto it : st) {
			cout << it.second << " ";
		}
		cout << "\n";
		for (int i = 0; i < k+1; ++i) {
			if (mp[i].empty())continue;
			printf("%d :: ",i);
			for (auto it2 = mp[i].begin(); it2 != mp[i].end(); ++it2) {
				cout << "(" << *it2 << ") ";
			}
			printf("\n");
		}
		printf("----------------------------->>>>\n");
	}
	for (auto it : st) {
		cout << it.first << " " << it.second << endl;
	}
	set<string> outcasts;
	for (auto it : st) {
		outcasts.insert(it.second);
	}
	for (auto it : mp) {
		if (it.empty())continue;
		for (auto it2 = it.begin(); it2 != it.end(); ++it2) {
			outcasts.insert(*it2);
		}
	}
	for (auto it : outcasts) {
		cout << "this" << it << endl;
	}
	return 0;
}