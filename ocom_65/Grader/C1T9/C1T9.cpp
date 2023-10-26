#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char lett = 'A', num = '1';
    scanf("%d", &n);
    for (int i = 0; i < n + 2; ++i)
    {
        for (int j = 0; j < 2 * n + 3; ++j)
        {
            if (i == 0 || i == n + 1 || j == 0 || j == 2 * n + 2)
            {
                printf("* ");
            }
            else if (j == n + 1)
            {
                if (i % 2 == 1)
                {
                    printf("%c ", lett);
                    ++lett;
                    if (lett == 91)
                    {
                        lett = 'A';
                    }
                }
                else
                {
                    printf("%c ", num);
                    ++num;
                    if (num == 58)
                    {
                        num = '1';
                    }
                }
            }
            else if (j <= i || j >= 2 * n + 2 - i)
            {
                printf(". ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}