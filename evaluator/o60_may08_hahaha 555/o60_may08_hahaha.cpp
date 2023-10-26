#include <bits/stdc++.h>
using namespace std;
struct node {
	int val;
	int rep;
	bool rev;
	long long inv;
	long long rnv;
	int c[5];
	int weight, size;
	node *left, *right;
	node(int k) : val(k), weight(rand()), size(1), rep(-1), c{0,0,0,0,0}, inv(0), rnv(0), rev(false), left(NULL), right(NULL) {};
} *root;

int size(node *t) {
	if (t) {
		return t->size;
	} else {
		return 0;
	}
}

int cnt(node *t, int a) {
	if (t) {
		return t->c[a];
	} else {
		return 0;
	}
}

long long inv(node *t) {
	if (t) {
		return t->inv;
	} else {
		return 0;
	}
}

long long rnv(node *t) {
	if (t) {
		return t->rnv;
	} else {
		return 0;
	}
}

void push(node *t) {
	if (t) {
		if (t->rev) {
			t->rev ^= 1;
			swap(t->inv,t->rnv);
			swap(t->left,t->right);
			if (t->left)t->left->rev ^= 1;
			if (t->right)t->right->rev ^= 1;
		}
		if (t->rep != -1) {
			// printf("before %d %d %d %d %d\n",t->c[0],t->c[1],t->c[2],t->c[3],t->c[4]);
			t->val = t->rep;
			for (int i = 0; i < 5; ++i) {
				t->c[i] = 0;
			}
			t->c[t->val] += t->size;
			t->inv = 0;
			t->rnv = 0;
			if (t->left)t->left->rep = t->rep;
			if (t->right)t->right->rep = t->rep;
			t->rep = -1;
			// printf("after %d %d %d %d %d\n",t->c[0],t->c[1],t->c[2],t->c[3],t->c[4]);
		}
	}
	return;
}

void split(node *treap, node *&left, node *&right, int x, int add = 0) {
	push(treap);
	if (!treap) {
		left = right = NULL;
		return;
	}
	int cursize = add+size(treap->left);
	if (cursize < x) {
		split(treap->right,treap->right,right,x,cursize+1);
		left = treap;
	} else {
		split(treap->left,left,treap->left,x,add);
		right = treap;
	}
	push(treap->left);
	push(treap->right);
	treap->size = 1+size(treap->left)+size(treap->right);
	for (int i = 0; i < 5; ++i) {
		treap->c[i] = cnt(treap->left,i)+cnt(treap->right,i);
	}
	++treap->c[treap->val];
	// printf("%d %d %d %d %d <\n",treap->c[0],treap->c[1],treap->c[2],treap->c[3],treap->c[4]);
	long long tracker = 0;
	treap->inv = inv(treap->left)+inv(treap->right);
	for (int i = 4; i > 0; --i) {
		tracker += cnt(treap->left,i);
		treap->inv += tracker*cnt(treap->right,i-1);
	}
	tracker = 0;
	treap->rnv = rnv(treap->left)+rnv(treap->right);
	for (int i = 0; i < 4; ++i) {
		tracker += cnt(treap->left,i);
		treap->rnv += tracker*cnt(treap->right,i+1);
	}
	for (int i = 4; i > treap->val; --i) {
		treap->inv += cnt(treap->left,i);
		treap->rnv += cnt(treap->right,i);
	}
	for (int i = 0; i < treap->val; ++i) {
		treap->inv += cnt(treap->right,i);		
		treap->rnv += cnt(treap->left,i);
	}
	return;
}

void merge(node *&treap, node *left, node *right) {
	// printf("newiter");
	// if (left)printf("%d ",left->val);
	// if (right)printf(" | %d",right->val);
	// printf("\n");
	push(left);
	push(right);
	// printf("pushed:\n");
	// if (left)printf("%d %d %d %d %d\n",left->c[0],left->c[1],left->c[2],left->c[3],left->c[4]);
	// if (right)printf("%d %d %d %d %d\n",right->c[0],right->c[1],right->c[2],right->c[3],right->c[4]);
	if (!left) {
		treap = right;
		// printf("xl %d %d %d %d %d > %d\n",treap->c[0],treap->c[1],treap->c[2],treap->c[3],treap->c[4],treap->rep);
		return;
	}
	if (!right) {
		treap = left;
		// printf("xr %d %d %d %d %d > %d\n",treap->c[0],treap->c[1],treap->c[2],treap->c[3],treap->c[4],treap->rep);
		return;
	}
	if (left->weight < right->weight) {
		// printf("LLLLL\n");
		merge(left->right,left->right,right);
		treap = left;
	} else {
		// printf("RRRRR\n");
		merge(right->left,left,right->left);
		treap = right;
	}
	push(treap->left);
	push(treap->right);
	treap->size = 1+size(treap->left)+size(treap->right);
	// printf("%d %d\n",treap->size,treap->val);
	// if(treap->left)printf("l %d %d %d %d %d >\n",treap->left->c[0],treap->left->c[1],treap->left->c[2],treap->left->c[3],treap->left->c[4]);
	// if(treap->right)printf("r %d %d %d %d %d >\n",treap->right->c[0],treap->right->c[1],treap->right->c[2],treap->right->c[3],treap->right->c[4]);
	for (int i = 0; i < 5; ++i) {
		treap->c[i] = cnt(treap->left,i)+cnt(treap->right,i);
	}
	++treap->c[treap->val];
	// printf("%d %d %d %d %d >\n",treap->c[0],treap->c[1],treap->c[2],treap->c[3],treap->c[4]);
	long long tracker = 0;
	treap->inv = inv(treap->left)+inv(treap->right);
	for (int i = 4; i > 0; --i) {
		tracker += cnt(treap->left,i);
		treap->inv += tracker*cnt(treap->right,i-1);
	}
	tracker = 0;
	treap->rnv = rnv(treap->left)+rnv(treap->right);
	for (int i = 0; i < 4; ++i) {
		tracker += cnt(treap->left,i);
		treap->rnv += tracker*cnt(treap->right,i+1);
	}
	for (int i = 4; i > treap->val; --i) {
		treap->inv += cnt(treap->left,i);
		treap->rnv += cnt(treap->right,i);
	}
	for (int i = 0; i < treap->val; ++i) {
		treap->inv += cnt(treap->right,i);		
		treap->rnv += cnt(treap->left,i);
	}
	return;
}

void setcolor(node *&treap, int a, int b, int c) {
	node *t1, *t2, *t3;
	split(treap,t1,t3,b);
	split(t1,t1,t2,a-1);
	// if(t1)printf("t1 %d %d %d %d %d >\n",t1->c[0],t1->c[1],t1->c[2],t1->c[3],t1->c[4]);
	// if(t2)printf("t2 %d %d %d %d %d >\n",t2->c[0],t2->c[1],t2->c[2],t2->c[3],t2->c[4]);
	// if(t3)printf("t3 %d %d %d %d %d >\n",t3->c[0],t3->c[1],t3->c[2],t3->c[3],t3->c[4]);
	t2->rep = c;
	// printf("%d <<<\n",c);
	merge(t1,t1,t2);
	// if(t1)printf("t1 %d %d %d %d %d >\n",t1->c[0],t1->c[1],t1->c[2],t1->c[3],t1->c[4]);
	// if(t3)printf("t3 %d %d %d %d %d >\n",t3->c[0],t3->c[1],t3->c[2],t3->c[3],t3->c[4]);
	merge(treap,t1,t3);
	// if(treap)printf("treap %d %d %d %d %d >\n",treap->c[0],treap->c[1],treap->c[2],treap->c[3],treap->c[4]);
	return;
}

void revers(node *&treap, int a, int b) {
	node *t1, *t2, *t3;
	split(treap,t1,t3,b);
	split(t1,t1,t2,a-1);
	t2->rev ^= 1;
	merge(t1,t1,t2);
	merge(treap,t1,t3);
// if(treap)printf("treap %d %d %d %d %d >\n",treap->c[0],treap->c[1],treap->c[2],treap->c[3],treap->c[4]);
	return;
}

void printinorder(node *&treap) {
	if (!treap) {
		return;
	}
	push(treap);
	printinorder(treap->left);
	printf("%d",treap->val);
	printinorder(treap->right);
	return;
}


long long countinversion(node *&treap, int a, int b) {
	node *t1, *t2, *t3;
	split(treap,t1,t3,b);
	split(t1,t1,t2,a-1);
	// printf("%d IJAND AND\n",ans);
	long long res = t2->inv;
	// printf("RAKIWR %d\n",ans);
	merge(t1,t1,t2);
	merge(treap,t1,t3);
	return res;
}

int main() {
	cin.tie(NULL);
	int n, q;
	scanf("%d%d",&n,&q);
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		node *nd = new node(str[i]-'0');
		++nd->c[str[i]-'0'];
		merge(root,root,nd);
		// printinorder(root);
		// printf(" <<<< %lld\n",root->inv);
		for (int j = 0; j < 5; ++j) {
			// printf("%d ",root->c[j]);
		}
		// printf("\n");
	}
	for (int i = 0; i < q; ++i) {
		// printinorder(root);
		// printf(" <<<< %lld\n",root->inv);
		// for (int j = 0; j < 5; ++j) {
		// 	printf("%d ",root->c[j]);
		// } 
		// printf("\n");
		int k;
		scanf("%d",&k);
		if (k == 1) {
			int a, b, c;
			scanf("%d%d%d",&a,&b,&c);
			setcolor(root,a,b,c);
		} else if (k == 2) {
			int a, b;
			scanf("%d%d",&a,&b);
			revers(root,a,b);
		} else if (k == 3) {
			int a, b;
			scanf("%d%d",&a,&b);
			printf("%lld\n",countinversion(root,a,b));
		}
	}

	return 0;
}