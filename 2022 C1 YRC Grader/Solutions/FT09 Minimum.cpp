#include <bits/stdc++.h>
using namespace std;

int main(){

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    cout << min(a, min(b, c));

    return 0;
}
