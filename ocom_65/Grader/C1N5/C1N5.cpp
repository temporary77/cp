#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n%d\n%d", n / 1440, n % 1440 / 60, n % 1440 % 60);

    return 0;
}