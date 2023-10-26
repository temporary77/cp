#include <iostream>
using namespace std;

int main()
{
    int n, osum = 0, esum = 0;
    for (int i = 0; i < 8; ++i)
    {
        scanf("%d", &n);
        if (n % 2 == 0)
        {
            esum += n;
        }
        else
        {
            osum += n;
        }
    }
    if (osum > esum)
    {
        printf("odd\n%d\n%d", esum, osum);
    }
    else if (osum == esum)
    {
        printf("equal\n%d\n%d", esum, osum);
    }
    else
    {
        printf("even\n%d\n%d", esum, osum);
    }
    return 0;
}