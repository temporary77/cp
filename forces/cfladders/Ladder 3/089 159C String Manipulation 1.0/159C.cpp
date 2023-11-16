#include <bits/stdc++.h>
using namespace std;

vector<int> vctr[26];
int tree[26][200001];
bool removed[200001];

void update(int x, int t, int val) {
	// printf("%d %d %d %d\n",x,t,vctr[t].size(),val);
	for (int a = x; a <= vctr[t].size(); a += a&-a) {
		// printf("%d %d %d %d %d<\n",t,a,tree[t][a],val,tree[t][a]+val);
		// printf("%d <<<<\n",tree[t][a]);
		tree[t][a] += val;
	}
	return;
}

int query(int x, int t) {
	int res = 0;
	for (int a = x; a > 0; a -= a&-a) {
		res += tree[t][a];
	}
	return res;
}

int main() {
	cin.tie(NULL);
	int k;
	scanf("%d",&k);
	string str;
	cin >> str;
	for (int i = 0; i < str.size()*k; ++i) {
		vctr[str[i%str.size()]-'a'].push_back(i);
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = 1; j <= vctr[i].size(); ++j) {
			update(j,i,1);
		}
	}
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		int a;
		char c;
		scanf("%d %c",&a,&c);
		int l = 1;
		int r = vctr[c-'a'].size();
		for (;;) {
			if (l >= r)break;
			int m = (l+r)/2;
			if (query(m,c-'a') >= a) {
				r = m;
			} else {
				l = m+1;
			}
		}
		removed[vctr[c-'a'][l-1]] = true;
		update(l,c-'a',-1);
	}
	for (int i = 0; i < str.size()*k; ++i) {
		if (!removed[i]) {
			printf("%c",str[i%str.size()]);
		}
	}
	return 0;
}