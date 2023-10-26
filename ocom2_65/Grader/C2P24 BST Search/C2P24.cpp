#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left, *right, *parent;
};

node* head = NULL;

//map<int,node*> mp;

node* createnode(int data) {
	node* newnode = new node;
	if (newnode == NULL)return NULL;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;
	return newnode;
}

void insert(int data) {
	if (head == NULL) {
		head = createnode(data);
		//mp[data] = head;
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
		newnode->parent = prev;
		//mp[data] = newnode;
	} else {
		prev->right = newnode;
		newnode->parent = prev;
		//mp[data] = newnode;
	}
	return;
}

/*node* findkey(int key) {
	if (mp[key] == NULL)return NULL;
	return mp[key];
}*/

node* findkey(int key) {
	node *iter = head;
	if (iter == NULL)return NULL;
	for (;iter != NULL;) {
		if (key == iter->data) {
			return iter;
		}
		if (key > iter->data) {
			iter = iter->right;
			continue;
		}
		if (key < iter->data) {
			iter = iter->left;
			continue;
		}
	}
	return NULL;
}

int worsefind(int key) {
	int min1 = INT_MAX, max1 = INT_MIN;
	node *iter = head;
	if (iter == NULL)return -1;
	for (;iter != NULL;) {
		if (key == iter->data) {
			return key;
		}
		if (key > iter->data) {
			max1 = max(iter->data,max1);
			iter = iter->right;
			continue;
		}
		if (key < iter->data) {
			min1 = min(iter->data,min1);
			iter = iter->left;
			continue;
		}
	}
	if (min1 == INT_MAX)return max1;
	if (max1 == INT_MIN)return min1;
	if (key-max1 > min1-key) {
		return min1;
	}
	return max1;
}

int successor(int x) {
	if (findkey(x) == NULL) {
		return -1;
	}
	if (findkey(x)->right != NULL) {
		node *iter = findkey(x)->right;
		for (;iter->left != NULL;) {
			iter = iter->left;
		}
		return iter->data;
	}
	if (findkey(x)->parent == NULL) {
		return -1;
	}
	node *iter = findkey(x)->parent;
	for (;x > iter->data && iter->parent != NULL;) {
		iter = iter->parent;
	}
	if (iter->parent == NULL) {
		return -1;
	}
	return iter->data;
}

int predecessor(int x) {
	if (findkey(x) == NULL) {
		return -1;
	}
	if (findkey(x)->left != NULL) {
		node *iter = findkey(x)->left;
		for (;iter->right != NULL;) {
			iter = iter->right;
		}
		return iter->data;
	}
	if (findkey(x)->parent == NULL) {
		return -1;
	}
	node *iter = findkey(x)->parent;
	for (;x <= iter->data && iter->parent != NULL;) {
		iter = iter->parent;
	}
	if (iter->parent == NULL) {
		return -1;
	}
	return iter->data;
}

int main() {
	//freopen("test_input3.txt","r",stdin);
	int n, k, x;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		insert(k);
	}
	scanf("%d%d",&x,&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		if (k == 1) {
			if (findkey(x) == NULL) {
				printf("NULL\n");
				continue;
			}
			printf("%d\n",findkey(x)->data);
		} else if (k == 2) {
			if (findkey(x) == NULL || findkey(x)->parent == NULL) {
				printf("NULL\n");
				continue;
			}
			printf("%d\n",findkey(x)->parent->data);
		} else if (k == 3) {
			if (successor(x) == -1) {
				printf("NULL\n");
				continue;
			}
			printf("%d\n",successor(x));
		} else if (k == 4) {
			if (predecessor(x) == -1) {
				printf("NULL\n");
				continue;
			}
			printf("%d\n",predecessor(x));
		} else if (k == 5) {
			if (worsefind(x) == -1) {
				printf("NULL\n");
				continue;
			}
			printf("%d\n",worsefind(x));
			continue;
		}
	}
	return 0;
}