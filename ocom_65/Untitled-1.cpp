#include <iostream>
using namespace std;

long long fac(long long ans, int n) {
    if(n == 0){
        return ans;
    }
    return fac(ans * n, n - 1)
}
long long fac2(int n) {
    if (n == 0) {
        return 1;
    }
    return n*fac2(n-1);
}
int main()
{
    printf("lld",fac(1,50));

    return 0;
}
