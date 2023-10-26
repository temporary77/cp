#include <iostream>
using namespace std;

int main()
{
    double m, f, h, x;
    scanf("%lf%lf%lf", &m, &f, &h);
    x = 0.4 * m + 0.5 * f + 0.1 * h;
    if (x >= 80)
    {
        printf("G");
    }
    else if (x >= 50)
    {
        printf("P");
    }
    else
    {
        printf("F");
    }
    return 0;
}