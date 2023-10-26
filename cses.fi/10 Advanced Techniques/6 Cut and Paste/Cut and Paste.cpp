#include <bits/stdc++.h>
using namespace std;

int n, m;

struct node {
	char val;
	int weight, size;
	node *left, *right;
	node(char c) : val(c), weight(rand()), size(1), left(NULL), right(NULL) {};
} *root;

int size(node *treap) {
	if (treap) {
		return treap->size;
	} else {
		return 0;
	}
}

void split(node *treap, node *&left, node *&right, int x, int add = 0) {
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
	return;
}

void merge(node *&treap, node *left, node *right) {
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
}

void printinorder(node *t) {
	if (t == NULL) {
		return;
	}
	printinorder(t->left);
	printf("%c",t->val);
	printinorder(t->right);
	return;
}

void addback(node *&treap, int l, int r) {
	node *t1, *t2, *t3;
	split(treap,t1,t2,l);
	split(t2,t2,t3,r-l+1);
	/*printinorder(t1);
	printf("\n");
	printinorder(t2);
	printf("\n");
	printinorder(t3);
	printf("\n");*/
	merge(treap,t1,t3);
	merge(treap,treap,t2);
}

int main() {
	cin.tie(NULL);
	scanf("%d%d",&n,&m);
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		merge(root,root,new node(str[i]));	
	}
	int a, b;
		/*printinorder(root);
		printf("\n");*/
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		addback(root,--a,--b);
		// printinorder(root);
		// printf("\n");
	}
	printinorder(root);
	return 0;
}