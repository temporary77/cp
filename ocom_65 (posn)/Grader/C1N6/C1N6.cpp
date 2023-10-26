#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", n / 1000, n % 1000 / 500, n % 500 / 100, n % 100 / 50, n % 50 / 20, n % 50 % 20 / 10, n % 10 / 5, n % 5);

    return 0;
}