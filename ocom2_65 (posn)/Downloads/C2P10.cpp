#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int v;
    struct node* n;
} node_t;

node_t* head = NULL;

node_t* createnode(int value) {
    node_t* newnode = new node_t;
    if (newnode == NULL)return head;
    newnode->v = value;
    newnode->n = NULL;
    return newnode;
}

void insert1(int value) {
    if (head == NULL) {
        node_t *newnode = createnode(value); 
        newnode->n = head; 
        head = newnode; 
        return;
    }
     if (head->v >= value) {
        node_t *newnode = createnode(value); 
        newnode->n = head; 
        head = newnode; 
        return;
    }   
    node_t* prev = head; 
    node_t* newnode = createnode(value);
    for (;prev->n != NULL && prev->n->v < newnode->v;) {
        prev = prev->n;
    } 
    newnode->n = prev->n;
    prev->n = newnode; 
    return;
}

void delete1(int value) {
    if (head == NULL) {
        printf("%d [not deleted]\n",value);
        return;
    }
    node_t* tmp = head;
    for (;tmp != NULL && tmp->v < value;) {
        tmp = tmp->n;
    }
    if (tmp->v != value) {
        printf("%d [not deleted]\n",value);
        return;
    }
    if (value == head->v) {
        if (head->n == NULL) {
            node_t* tmp = head;
            head = NULL;
            free(tmp);
        } else {
            node_t* tmp = head;
            head = head->n;
            free(tmp);
        }
        printf("%d [deleted]\n",value);
        return;
    }
    node_t* prev = head;
    tmp = head;
    for (;tmp != NULL && tmp->v < value;) {
        prev = tmp;
        tmp = tmp->n;
    }
    prev->n = tmp->n;
    free(tmp);
    printf("%d [deleted]\n",value);
    return;
}

void print() {
    node_t* cur = head;
    for (;cur != NULL;) {
        printf("%d ",cur->v);
        cur = cur->n;
    }
    printf("\n");
    return;
}

int main() {
    int n, k;
    scanf("%d",&n);
    char c;
    for (int i = 0; i < n; ++i) {
        scanf(" %c",&c);
        if (c == 'i') {
            scanf("%d",&k);
            insert1(k);
        } else if (c == 'd') {
            scanf("%d",&k);
            delete1(k);
        } else if (c == 'p') {
            print();
        }
        //cout << "k = " << k << endl ; 
    }
    
    return 0;
}