#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1 - n; i <= n - 1; ++i)
    {
        for (int j = 1 - n; j <= n - 1; ++j)
        {
            if (i == j || -1 * i == j)
            {
                if (i == 0)
                {
                    printf("%c", 65 + (n - 1) % 26);
                }
                else
                {
                    if (i < 0)
                    {
                        if (j < 0)
                        {
                            printf("%d", (abs(j) * 4 - 3) % 10);
                        }
                        else
                        {
                            printf("%d", (abs(j) * 4) % 10);
                        }
                    }
                    else
                    {
                        if (j < 0)
                        {
                            printf("%d", (abs(j) * 4 - 1) % 10);
                        }
                        else
                        {
                            printf("%d", (abs(j) * 4 - 2) % 10);
                        }
                    }
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}