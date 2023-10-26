#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int v;
    struct node* n;
} node_t;

node_t* head = NULL;

node_t* createnode(int value) {
    node_t* newnode = new node_t;
    if (newnode == NULL)return NULL;
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
    node_t* prev = head;
    for (;prev-> n != NULL && prev->v < value;) {
        prev = prev->n;
    }
    if (prev->v != value) {
        printf("%d [not deleted]\n",value);
        return;
    }
    if (value == head->v) {
        if (head->n == NULL) {
            node_t* prev = head;
            head = NULL;
            free(prev);
        } else {
            node_t* prev = head;
            head = head->n;
            free(prev);
        }
        printf("%d [deleted]\n",value);
        return;
    }
    prev = head;
    node_t* temp = head;
    for (;temp != NULL && temp->v < value;) {
        prev = temp;
        temp = temp->n;
    }
    prev->n = temp->n;
    free(temp);
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
    //n = 999999;
    char c;
    for (int i = 0; i < n; ++i) {
        scanf(" %c",&c);
        /*int randet = rand()%2;
        if (randet == 0)c = 'i';
        if (randet == 1)c = 'd';
        int k = rand()%10;
        printf("%c %d\n",c,k);*/
        //print();
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