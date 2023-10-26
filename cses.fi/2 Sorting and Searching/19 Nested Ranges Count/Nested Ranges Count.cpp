#include <bits/stdc++.h>
using namespace std;

tuple<int,int,int> arr[200002];
vector<int> tree1[200002];
vector<int> tree2[200002];
int ans1[200002];
int ans2[200002];
int n;
int a, b;

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b) {
	if (get<0>(a) != get<0>(b)) {
		return get<0>(a) < get<0>(b);
	} else {
		return get<1>(a) > get<1>(b);
	}
}

void build() {
	for (int i = 1; i <= n; ++i) {
		for (int j = i-(i&-i)+1; j <= i; ++j) {
			tree1[i].push_back(get<1>(arr[n-j+1]));
			tree2[i].push_back(get<1>(arr[j]));
		}
		sort(tree1[i].begin(),tree1[i].end());
		sort(tree2[i].begin(),tree2[i].end());
	}
	return;
}

pair<int,int> query(int nde) {
	int suma = 0;
	int sumb = 0;
	int d = n-nde+1;
	int b = get<1>(arr[nde]);
	--nde;
	--d;
	for (;nde > 0; nde -= nde&-nde) {
		//printf("analyze with b %d and node %d\n",b,nde);
		/*for (auto it : tree2[nde]) {
			printf("%d ",it);
		}
		printf("\n");*/
		sumb += tree2[nde].end()-lower_bound(tree2[nde].begin(),tree2[nde].end(),b);
		//printf("sumb now %d\n",sumb);
	}
	for (;d > 0; d -= d&-d) {
		//printf("analyze with a %d and node %d\n",b,d);
		/*for (auto it : tree1[d]) {
			printf("%d ",it);
		}
		printf("\n");*/
		suma += upper_bound(tree1[d].begin(),tree1[d].end(),b)-tree1[d].begin();
		//printf("suma now %d\n",suma);
	}
	return {suma,sumb};
}

int main() {
	//freopen("2-19input.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d",&a,&b);
		arr[i] = {a,b,i};
	}
	sort(arr+1,arr+n+1,cmp);
	build();
	/*for (int i = 1; i <= n; ++i) {
		for (auto it : tree2[i]) {
			printf("%d ",it);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; ++i) {
		for (auto it : tree1[i]) {
			printf("%d ",it);
		}
		printf("\n");
	}*/
	pair<int,int> q;
	for (int i = 1; i <= n; ++i) {
		q = query(i);
		ans1[get<2>(arr[i])] = q.first;
		ans2[get<2>(arr[i])] = q.second;
		//printf(">>> %d %d\n",ans1[get<2>(arr[i])],ans2[get<2>(arr[i])]);
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ",ans1[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ",ans2[i]);
	}
	//printf("\ndone and dusted");
	return 0;
}
/*
1 6
2 4
4 8
3 6
*/