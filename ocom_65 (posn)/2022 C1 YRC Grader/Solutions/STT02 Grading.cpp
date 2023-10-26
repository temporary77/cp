#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int L = 50;

struct person {
    char *fname, *lname;
    int sc;
    person(): fname(NULL), lname(NULL), sc(0) {}
    person(char *f, char *l, int s){
        fname = new char[L + 5];
        lname = new char[L + 5];
        strcpy(fname, f);
        strcpy(lname, l);
        sc = s;
    }
};

person arr[N + 5];

int main(){

    int n, nTests;
    scanf("%d%d", &n, &nTests);
    for(int i = 1; i <= n; ++i){
        char fname[L + 5], lname[L + 5];
        scanf("%s%s", fname, lname);
        int mn = 1e9;
        int sum = 0;
        for(int j = 1; j <= nTests; ++j){
            int x;
            scanf("%d", &x);
            sum += x;
            mn = min(mn, x);
        }
        arr[i] = person(fname, lname, sum - mn);
    }
    int th;
    scanf("%d", &th);
    double pass = (double)(nTests - 1) * th / 10;
    for(int i = 1; i <= n; ++i){
        if(arr[i].sc >= pass){
            printf("%s %s\n", arr[i].fname, arr[i].lname);
        }
    }

    return 0;
}
