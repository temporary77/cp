#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
};\

node* head = NULL;

node* createnode(int data) {
	node* newnode = new node;
	if (newnode == NULL)return NULL;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void insert(int data) {
	if (head == NULL) {
		head = createnode(data);
		return;
	}
	node *newnode = createnode(data);
	node *iter = head, *prev;
	for (;iter != NULL;) {
		prev = iter;
		if (iter->data > newnode->data) {
			iter = iter->left;
		} else {
			iter = iter->right;
		}
	}
	if (prev->data > newnode->data) {
		prev->left = newnode;
	} else {
		prev->right = newnode;
	}
	return;
}

void preorder(node* iter) {
	printf("%d ",iter->data);
	if(iter->left != NULL)preorder(iter->left);
	if(iter->right != NULL)preorder(iter->right);
	return;
}

void inorder(node* iter) {
	if(iter->left != NULL)inorder(iter->left);
	printf("%d ",iter->data);
	if(iter->right != NULL)inorder(iter->right);
	return;
}

void postorder(node* iter) {
	if(iter->left != NULL)postorder(iter->left);
	if(iter->right != NULL)postorder(iter->right);
	printf("%d ",iter->data);
	return;
}

void bfs() {
	queue<node*> que;
	if (head == NULL)return;
	que.push(head);
	for (int i = 0; !que.empty(); ++i) {
		int s = que.size();
		printf("%d:",i);
		for (int j = 0; j < s; ++j) {
			node* temp = que.front();
			printf("%d ",temp->data);
			que.pop();
			if (temp->left != NULL) {
				que.push(temp->left);
			}
			if (temp->right != NULL) {
				que.push(temp->right);
			}
		}
		printf("\n");
	}
	return;
}

void leaves(node* iter) {
	if(iter->left != NULL)leaves(iter->left);
	if(iter->left == NULL && iter->right == NULL)printf("%d ",iter->data);
	if(iter->right != NULL)leaves(iter->right);
	return;
}

int main() {
	//freopen("test_input3.txt","r",stdin);
	int n, k;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		insert(k);
	}
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		if (k == 1) {
			preorder(head);
			printf("\n");
		} else if (k == 2) {
			inorder(head);
			printf("\n");
		} else if (k == 3) {
			postorder(head);
			printf("\n");
		} else if (k == 4) {
			bfs();
		} else if (k == 5) {
			leaves(head);
			printf("\n");
		}
	}
	return 0;
}