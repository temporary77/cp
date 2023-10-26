#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    scanf("%d%d%d\n%d%d%d", &a, &b, &c, &d, &e, &f);
    printf("%.3d", ((100 * (a % 10) + 10 * (b % 10) + (c % 10)) + (100 * (d % 10) + 10 * (e % 10) + (f % 10))) % 1000);

    return 0;
}