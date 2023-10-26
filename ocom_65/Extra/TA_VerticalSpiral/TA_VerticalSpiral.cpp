#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    char c = 'A', n = '0';
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (w != 1)
            {
                if ((i / (w - 1) % 2 == 0 && i % (w - 1) == j) || (i / (w - 1) % 2 == 1 && i % (w - 1) == (w - 1) - j))
                {
                    printf("%c", c);
                    if ((i / (w - 1) % 2 == 1 && i % (w - 1) == j) || (i / (w - 1) % 2 == 0 && i % (w - 1) == (w - 1) - j))
                    {
                        if (n == '9')
                        {
                            n = '0';
                        }
                        else
                        {
                            ++n;
                        }
                    }
                    if (c == 'Z')
                    {
                        c = 'A';
                    }
                    else
                    {
                        ++c;
                    }
                }
                else if ((i / (w - 1) % 2 == 1 && i % (w - 1) == j) || (i / (w - 1) % 2 == 0 && i % (w - 1) == (w - 1) - j))
                {
                    printf("%c", n);
                    if (n == '9')
                    {
                        n = '0';
                    }
                    else
                    {
                        ++n;
                    }
                }
                else
                {
                    printf(" ");
                }
            }
            else
            {
                printf("%c", c);
                ++n;
                if (c == 'Z')
                {
                    c = 'A';
                }
                else
                {
                    ++c;
                }
            }
        }
        printf("\n");
    }
    return 0;
}