#include <bits/stdc++.h>
using namespace std;

struct node {
	int l, max1, r;
	node *left, *right;
	node(int l, int max1, int r, node* left, node* right) : l(l), max1(max1), r(r), left(left), right(right) {};
};

int n;
int arr[100001];
node *perstree[100001];
vector<pair<int,int>> vctr;
vector<pair<int,int>> heights;

node* build(int a, int b) {
	if (a > b)return NULL;
	if (a == b) {
		return new node(0,0,0,NULL,NULL);
	}
	return new node(0,0,0,build(a,(a+b)/2),build((a+b)/2+1,b));
}

node* update(node* n, int a, int b, int x) {
	if (a > b)return NULL;
	if (a == b) {
		return new node(1,1,1,NULL,NULL);
	}
	node* nleft;
	node* nright;
	if (x <= (a+b)/2) {
		nleft = update(n->left,a,(a+b)/2,x);
		nright = n->right;
	} else {
		nright = update(n->right,(a+b)/2+1,b,x);
		nleft = n->left;
	}
	int nl = nleft->l;
	if (nleft->l == (a+b)/2-a+1) {
		nl += nright->l;
	}
	int nr = nright->r;
	if (nright->r == b-(a+b)/2) {
		nr += nleft->r;
	}
	int nmax = max(nl,nr);
	nmax = max(nmax,nleft->max1);
	nmax = max(nmax,nright->max1);
	nmax = max(nmax,nleft->r+nright->l);
	return new node(nl,nmax,nr,nleft,nright);
}

tuple<int,int,int> query(node *n, int a, int b, int x, int y) {
	if (a > b || b < x || y < a) {
		return (tuple<int,int,int>){0,0,0};
	}
	if (x <= a && b <= y) {
		return (tuple<int,int,int>){n->l,n->max1,n->r};
	}
	tuple<int,int,int> q1 = query(n->left,a,(a+b)/2,x,y);
	tuple<int,int,int> q2 = query(n->right,(a+b)/2+1,b,x,y);
	// printf("%d %d and %d %d\n",a,(a+b)/2,(a+b)/2+1,b);
	// printf("%d %d %d and %d %d %d\n",get<0>(q1),get<1>(q1),get<2>(q1),get<0>(q2),get<1>(q2),get<2>(q2));
	int nl = get<0>(q1);
	if (nl == (a+b)/2-a+1) {
		nl += get<0>(q2);
	}
	int nr = get<2>(q2);
	if (nr == b-(a+b)/2) {
		nr += get<2>(q1);
	}
	int nmax = max(nl,nr);
	// printf("raw %d %d %d %d %d\n",nl,nr,get<1>(q1),get<1>(q2),get<2>(q1)+get<0>(q2));
	// printf("%d\n",max(get<1>(q1),get<1>(q2)));
	nmax = max(nmax,max(max(get<1>(q1),get<1>(q2)),get<2>(q1)+get<0>(q2)));
	// printf("%d\n",nmax);
	return (tuple<int,int,int>){nl,nmax,nr};
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
		vctr.push_back({arr[i],i});
	}
	sort(vctr.begin(),vctr.end(),greater<pair<int,int>>());
	// for (auto it : vctr) {
	// 	printf("{%d,%d} ",it);
	// }
	// printf("\n");
	perstree[0] = build(1,n);
	int prev = -1;
	for (int i = 0; i < vctr.size(); ++i) {
		int idx = vctr[i].second;
		if (vctr[i].first != prev) {
			if (prev != -1) {
				heights.push_back({prev,i});
			}
			prev = vctr[i].first;
		}
		// printf("%d %d <<\n",i+1,idx);
		perstree[i+1] = update(perstree[i],1,n,idx);
	}
	heights.push_back({prev,vctr.size()});
	// for (auto it : heights) {
	// 	printf("%d %d\n",it);
	// }
	// printf(">>> %d %d %d\n",get<0>(query(perstree[4],1,n,1,2)),get<1>(query(perstree[4],1,n,1,2)),get<2>(query(perstree[4],1,n,1,2)));
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		int ql, qr, w;
		scanf("%d%d%d",&ql,&qr,&w);
		int l = 0;
		int r = heights.size()-1;
		for (;;) {
			if (l >= r)break;
			int m = (l+r)/2;
			pair<int,int> pr = heights[m];
			// printf("%d %d %d %d %d bs\n",l,r,m,pr);
			if (get<1>(query(perstree[pr.second],1,n,ql,qr)) >= w) {
				r = m;
			} else {
				l = m+1;
			}
		}
		// printf("fin %d\n",l);
		printf("%d\n",heights[l].first);
	}
	return 0;
}