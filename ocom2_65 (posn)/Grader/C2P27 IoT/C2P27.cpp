#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	vector<pair<int,string>> vctr;
	priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
	string str;
	int oc;
	int min1 = INT_MAX;
	for (int i = 0; i < n; ++i) {
		cin >> str >> oc;
		min1 = min(min1,oc);
		vctr.push_back({oc,str});
	}
	int max1 = min1*k, t;
	for (int i = 0; i < n; ++i) {
		t = max1/vctr[i].first;
		for (int j = 1; j <= t; ++j) {
			pq.push({(vctr[i].first)*j,(vctr[i].second)});
		}
	}
	for (int i = 0; i < k; ++i) {
		cout << (pq.top()).first << " " << (pq.top()).second << endl;
		pq.pop();
	}

	return 0;
}