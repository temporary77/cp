#include <iostream>
using namespace std;

int main()
{
    int n, max = -32768, min = 32767;
    for (int i = 0; i < 10; ++i)
    {
        scanf("%d", &n);
        if (n > 0)
        {
            if (n >= max)
            {
                max = n;
            }
            if (n <= min)
            {
                min = n;
            }
        }
    }
    printf("%d %d", max, min);
    return 0;
}