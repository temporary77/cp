#include <bits/stdc++.h>
using namespace std;

int main()
{
    char arr[3], a, s;
    for (int i = 0; i < 3; ++i)
    {
        scanf(" %c", &arr[i]);
    }
    scanf(" %c %c", &a, &s);
    while (a != 'X' && s != 'X')
    {
        if (s == 'L')
        {
            if (a - 66 >= 0)
            {
                swap(arr[int(a - 65)], arr[int(a - 66)]);
            }
        }
        else if (s == 'R')
        {
            if (a - 64 <= 2)
            {
                swap(arr[int(a - 65)], arr[int(a - 64)]);
            }
        }
        scanf(" %c %c", &a, &s);
    }
    for (int i = 0; i < 3; ++i)
    {
        if (arr[i] == 'T')
        {
            printf("Triangle\n");
        }
        else if (arr[i] == 'S')
        {
            printf("Star\n");
        }
        else if (arr[i] == 'C')
        {
            printf("Candy\n");
        }
    }
    return 0;
}
