#include <iostream>
using namespace std;

int main()
{
    int a, sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        scanf("%d", &a);
        sum += a;
    }
    printf("%d\n%.2lf", sum, (double)sum / 5);

    return 0;
}