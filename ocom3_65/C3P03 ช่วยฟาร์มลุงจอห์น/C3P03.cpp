#include <bits/stdc++.h>
using namespace std;

int arr[100001];
vector<int> tree[100001];
//unordered_map<int,int> updates;
int n, m;

void build() {
	for (int i = 1; i <= n; ++i) {
		for (int j = i-(i&-i)+1; j <= i; ++j) {
			tree[i].insert(upper_bound(tree[i].begin(),tree[i].end(),arr[j]),arr[j]);
			//tree[i].push_back(arr[j]);
		}
		//sort(tree[i].begin(),tree[i].end());
	}
	return;
}

void update(int a, int x) {
	int d = arr[a];
	arr[a] = x;
	for (;a <= n; a += a&-a) {
		auto it = lower_bound(tree[a].begin(),tree[a].end(),d);
		auto it2 = lower_bound(tree[a].begin(),tree[a].end(),x);
		*it = x;
		if (it < it2) {
			rotate(it,it+1,it2);
		} else {
			rotate(it2,it,it+1);
		}
		//tree[a].erase(lower_bound(tree[a].begin(),tree[a].end(),d));
		//tree[a].insert(lower_bound(tree[a].begin(),tree[a].end(),x),x);
	}
	return;
	/*for (;!updates.empty();) {
		int a = (*updates.begin()).first;
		int x = (*updates.begin()).second;
		int d = arr[a];
		arr[a] = x;
		for (;a <= n; a += a&-a) {
			tree[a].erase(lower_bound(tree[a].begin(),tree[a].end(),d));
			tree[a].insert(lower_bound(tree[a].begin(),tree[a].end(),x),x);
		}
		updates.erase(updates.begin());
	}
	return;*/
}

int query(int a, int b, int x) {
	int sa = 0, sb = 0;
	--a;
	for (;;) {
		if (b == a)break;
		if (b > a) {
			sb += upper_bound(tree[b].begin(),tree[b].end(),x)-tree[b].begin();
			b -= b&-b;
		} else {
			sa += upper_bound(tree[a].begin(),tree[a].end(),x)-tree[a].begin();
			a -= a&-a;
		}
	}
	return sb-sa;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	build();
	char c;
	int a, b, x;
	for (int i = 0; i < m; ++i) {
		scanf(" %c",&c);
		if (c == 'C') {
			scanf("%d%d%d",&a,&b,&x);
			//update();
			printf("%d\n",query(a,b,x));
		} else if (c == 'M') {
			scanf("%d%d",&a,&x);
			update(a,x);
			//updates[a] = x;
		}
	}
	return 0;
}