#include <iostream>
using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%.2lf\n%d", a * (double)b / 2, a * b);

    return 0;
}