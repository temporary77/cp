#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, p, q, c;
    scanf("%d%d%d%d", &m, &n, &p, &q);
    if (n != p)
    {
        printf("No Solution");
        return 0;
    }
    int A[m][n], result[m][q] = {};
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < q; ++j)
        {
            scanf("%d", &c);
            for (int k = 0; k < m; ++k)
            {
                result[k][j] += A[k][i] * c;
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < q; ++j)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}