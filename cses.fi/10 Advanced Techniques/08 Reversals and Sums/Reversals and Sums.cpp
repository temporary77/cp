#include <bits/stdc++.h>
using namespace std;

int n, m;

struct node {
	long long val;
	int weight, size;
	long long sum;
	bool rev;
	node *left, *right;
	node(long long c) : val(c), weight(rand()), size(1), sum(c), rev(false), left(NULL), right(NULL) {};
} *root;

int size(node *treap) {
	if (treap) {
		return treap->size;
	} else {
		return 0;
	}
}

long long sum(node *treap) {
	if (treap) {
		return treap->sum;
	} else {
		return 0;
	}
}

void revers(node* &treap) {
	if (treap && treap->rev) {
		treap->rev ^= 1;
		swap(treap->left,treap->right);
		if(treap->left)treap->left->rev ^= 1;
		if(treap->right)treap->right->rev ^= 1;
	}
	return;
}

void split(node *treap, node *&left, node *&right, int x, int add = 0) {
	revers(treap);
	if (!treap) {
		left = right = NULL;
		return;
	}
	int cursize = add+size(treap->left);
	if (cursize < x) {
		split(treap->right, treap->right, right, x, cursize+1);
		left = treap;
	} else {
 		split(treap->left, left, treap->left, x, add);
 		right = treap;
	}
	treap->size = 1+size(treap->left)+size(treap->right);
	treap->sum = treap->val+sum(treap->left)+sum(treap->right);
	return;
}

void merge(node *&treap, node *left, node *right) {
	revers(left);
	revers(right);
	if (left == NULL) {
		treap = right;
		return;
	}
	if (right == NULL) {
		treap = left;
		return;
	}
	if (left->weight < right->weight) {
		merge(left->right,left->right,right);
		treap = left;
	} else {
		merge(right->left,left,right->left);
		treap = right;
	}
	treap->size = 1+size(treap->left)+size(treap->right);
	treap->sum = treap->val+sum(treap->left)+sum(treap->right);
	return;
}

void rev(node *&treap, int l, int r) {
	node *t1, *t2, *t3;
	split(treap,t1,t2,l);
	split(t2,t2,t3,r-l+1);
	t2->rev ^= 1;
	/*printinorder(t1);
	printf("\n");
	printinorder(t2);
	printf("\n");
	printinorder(t3);
	printf("\n");*/
	merge(treap,t1,t2);
	merge(treap,treap,t3);
}

void querysum(node *&treap, int l, int r) {
	node *t1, *t2, *t3;
	split(treap,t1,t2,l);
	split(t2,t2,t3,r-l+1);
	printf("%lld\n",t2->sum);
	/*printinorder(t1);
	printf("\n");
	printinorder(t2);
	printf("\n");
	printinorder(t3);
	printf("\n");*/
	merge(treap,t1,t2);
	merge(treap,treap,t3);
	return;
}

int main() {
	cin.tie(NULL);
	scanf("%d%d",&n,&m);
	long long k;
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&k);
		merge(root,root,new node(k));	
	}
	int a, b;
		/*printinorder(root);
		printf("\n");*/
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&k,&a,&b);
		if (k == 1) {
			rev(root,--a,--b);
		} else if (k == 2) {
			querysum(root,--a,--b);
		}
	}
	return 0;
}