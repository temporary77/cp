#include <bits/stdc++.h>
using namespace std;

int main()
{
    char n[1000002] = {}, m[1000002] = {}, k[1000002] = {}, a;
    scanf("%s\n%s\n%s", n, m, k);
    int nlength = strlen(n), mlength = strlen(m), klength = strlen(k);
    for (int i = 0; i < nlength; ++i)
    {
        n[1000001 - i] = n[nlength - 1 - i];
        n[nlength - 1 - i] = '\0';
    }
    for (int i = 0; i < mlength; ++i)
    {
        m[1000001 - i] = m[mlength - 1 - i];
        m[mlength - 1 - i] = '\0';
    }
    for (int i = 0; i < klength; ++i)
    {
        k[1000001 - i] = k[klength - 1 - i];
        k[klength - 1 - i] = '\0';
    }
    for (int i = 0; i < max(nlength, mlength); ++i)
    {
        if (n[1000001 - i] == '\0')
        {
            n[1000001 - i] = '0';
            nlength++;
        }
        if (m[1000001 - i] == '\0')
        {
            m[1000001 - i] = '0';
            mlength++;
        }
        n[1000001 - i] += m[1000001 - i] - 48;
        if (n[1000001 - i] > 57)
        {
            n[1000001 - i] -= 10;
            if (n[1000000 - i] == '\0')
            {
                n[1000000 - i] = '1';
                nlength++;
            }
            else
            {
                n[1000000 - i]++;
            }
        }
    }
    bool switch1 = 0;
    for (int i = max(nlength, klength) - 1; i >= 0; --i)
    {
        if (n[1000001 - i] == '\0')
        {
            n[1000001 - i] = '0';
            nlength++;
        }
        if (k[1000001 - i] == '\0')
        {
            k[1000001 - i] = '0';
            klength++;
        }
        if (switch1 == 0)
        {
            n[1000001 - i] -= k[1000001 - i] - 48;
            if (n[1000001 - i] < 48)
            {
                if (n[1000000 - i] == '\0')
                {
                    switch1 = 1;
                    n[1000001 - i] += k[1000001 - i] - 48;
                    n[1000001 - i] = k[1000001 - i] - n[1000001 - i] + 48;
                }
            }
        }
        else
        {
            n[1000001 - i] = k[1000001 - i] - n[1000001 - i] + 48;
        }
    }
    for (int i = 0; i < nlength; ++i)
    {
        if (n[1000001 - i] < 48)
        {
            n[1000001 - i] += 10;
            n[1000000 - i]--;
        }
    }
    if (switch1 == 1)
    {
        printf("-");
    }
    switch1 = 0;
    for (int i = 1000002 - nlength; i < 1000002; ++i)
    {
        if (n[i] == '0')
        {
            if (i == 1000001)
            {
                printf("%c", n[i]);
            }
            else if (switch1 == 1)
            {
                printf("%c", n[i]);
            }
        }
        else
        {
            printf("%c", n[i]);
            switch1 = 1;
        }
    }

    return 0;
}