#include <bits/stdc++.h>
using namespace std;

struct person {
    int id;
    double gpa;
    person(): id(0), gpa(0) {}
    person(int i, double g): id(i), gpa(g) {}
};

const int N = 1000;

person arr[N + 5];

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d%lf", &arr[i].id, &arr[i].gpa);
    }
    double pass;
    scanf("%lf", &pass);
    bool found = false;
    for(int i = 1; i <= n; ++i){
        person &x = arr[i];
        if(x.gpa >= pass){
            found = true;
            cout << x.id << '\n';
        }
    }
    if(!found){
        cout << "None";
    }

    return 0;
}
