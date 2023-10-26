#include <bits/stdc++.h>
using namespace std;

struct node {
	int val;
	int weight, size;
	bool rev;
	node *left, *right;
	node(int k) : val(k), weight(rand()), size(1), rev(false), left(NULL), right(NULL) {};
} *root;

int size(node *t) {
	if (t) {
		return t->size;
	} else {
		return 0;
	}
}

void revers(node *t) {
	if (t && t->rev) {
		t->rev ^= 1;
		swap(t->left,t->right);
		if(t->left)t->left->rev ^= 1;
		if(t->right)t->right->rev ^= 1;
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
		split(treap->right,treap->right,right,x,cursize+1);
		left = treap;
	} else {
		split(treap->left,left,treap->left,x,add);
		right = treap;
	}
	treap->size = 1+size(treap->left)+size(treap->right);
	return;
}

void merge(node *&treap, node *left, node *right) {
	revers(left);
	revers(right);
	if (!left) {
		treap = right;
		return;
	}
	if (!right) {
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
	return;
}

void printinorder(node *&treap) {
	if (!treap) {
		return;
	}
	printinorder(treap->left);
	printf("%d ",treap->val);
	printinorder(treap->right);
	return;
}

void rev(node *&treap, int r) {
	node *t1;
	split(treap,treap,t1,r);
	// printinorder(treap);
	// printf("\n");
	// printinorder(t1);
	// printf("\n");
	treap->rev ^= 1;
	merge(treap,treap,t1);
	return;
}

int leftmost(node *&treap) {
	revers(treap);
	if (treap->left == NULL) {
		return treap->val;
	} else {
		return leftmost(treap->left);
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int k;
	int idx;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		if (i == 0)idx = k;
		merge(root,root,new node(k));
	}
	int cnt = 0;
	for (;;) {
		rev(root,idx);
		++cnt;
		idx = leftmost(root);
		// printf("%d\n",idx);
		// printinorder(root);
		// printf("\n");
		if (idx == 1) {
			break;
		}
	}
	printf("%d",cnt);
	return 0;
}