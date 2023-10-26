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

void insert1(int index, int value) {
    if (index < 0) {
        printf("[%d: %d not inserted]\n",index,value);
        return;
    }
    if (index == 0) {
        node_t* newnode = createnode(value);
        newnode->n = head;
        head = newnode;        
        return;
    }
    node_t* iter = head;
    for (int i = 1; i < index; ++i) {
        iter = iter->n;
        if (iter == NULL) {
            printf("[%d: %d not inserted]\n",index,value);
            return;
        }
    }
    if (iter == NULL) {
        printf("[%d: %d not inserted]\n",index,value);
        return;
    }
    node_t* newnode = createnode(value);
    newnode->n = iter->n;
    iter->n = newnode;
    return;
}

void delete1(int index) {
    if (head == NULL || index < 0) {
        printf("[%d: not deleted]\n",index);
        return;
    }
    if (index == 0) {
        printf("[%d: %d deleted]\n",index,head->v);
        node_t* prev = head;
        head = head->n;
        free(prev);
        return;      
    }
    node_t* iter = head;
    node_t* temp = head;
    for (int i = 0; i < index; ++i) {
        iter = temp;
        if (temp->n == NULL) {
            printf("[%d: not deleted]\n",index);
            return;
        }
        temp = temp->n;
    }
    printf("[%d: %d deleted]\n",index,temp->v);
    iter->n = temp->n;
    free(temp);
    return;
}

void getvalue(int index) {
    if (head == NULL || index < 0) {
        printf("[%d: invalid index]\n",index);
        return;
    }
    node_t* iter = head;
    for (int i = 0; i < index; ++i) {
        iter = iter->n;
        if (iter == NULL) {
            printf("[%d: invalid index]\n",index);
            return;
        }
    }
    printf("%d: %d\n",index,iter->v);
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
    //freopen("test_input.txt","r",stdin);
    int n, k, l;
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
            scanf("%d%d",&k,&l);
            insert1(k,l);
        } else if (c == 'd') {
            scanf("%d",&k);
            delete1(k);
        } else if (c == 'v') {
            scanf("%d",&k);
            getvalue(k);
        } else if (c == 'p') {
            print();
        }
        //cout << "k = " << k << endl ; 
    }
    return 0;
}