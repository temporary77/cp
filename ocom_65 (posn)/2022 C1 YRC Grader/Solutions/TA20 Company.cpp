#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int L = 1e6;

struct employee {
    int salary, gpa, order;
    employee(): salary(0), gpa(0), order(0) {}
    employee(int s, int g, int o): salary(s), gpa(g), order(o) {}
    bool operator < (const employee &rhs) const {
        if(salary != rhs.salary){
            return salary > rhs.salary;
        } else if(gpa != rhs.gpa){
            return gpa > rhs.gpa;
        }
        return order < rhs.order;
    }
};

char str[L + 5];
employee arr[N + 5];

int toDec(const char *tok, int base){
    int len = strlen(tok);
    int ans = 0;
    for(int i = 0; i < len; ++i){
        char c = tok[i];
        ans *= base;
        if(isalpha(c)){
            ans += 10 + c - 'A';
        } else {
            ans += c - '0';
        }
    }
    return ans;
}

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf(" %[^,\n]%*+c", str);
        int j = 1;
        for(char *tok = strtok(str, "()"); tok != NULL && j <= 3; tok = strtok(NULL, "()"), ++j){
            if(j == 1){
                arr[i].salary = toDec(tok, 16);
            } else if(j == 2){
                arr[i].gpa = atoi(tok);
            } else if(j == 3){
                arr[i].order = toDec(tok, 2);
            }
        }
    }
    sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; ++i){
        employee &x = arr[i];
        cout << x.salary << ' ' << x.gpa << ' ' << x.order << '\n';
    }

    return 0;
}
