#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (((i < n / 2 && i % 2 == 0) || (i >= n / 2 && i % 2 == (n - 1) % 2)) && ((j < n / 2 && j % 2 == 0) || (j >= n / 2 && j % 2 == (n - 1) % 2)))
            {
                printf("*");
            }
            else if ((((i < n / 2 && i % 2 == 0) || (i >= n / 2 && i % 2 == (n - 1) % 2)) && ((j > i && j < n - 1 - i) || (j > n - 1 - i && j < i))) || (((j < n / 2 && j % 2 == 0) || (j >= n / 2 && j % 2 == (n - 1) % 2)) && ((i > j && i < n - 1 - j) || (i > n - 1 - j && i < j))))
            {
                printf("*");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}