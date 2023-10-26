#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char arr[1000000];
    scanf("%[^\n]%d", arr, &n);
    int range = strlen(arr);
    for (int i = 0; i < range; ++i)
    {
        if (arr[i] >= 97 && arr[i] <= 122)
        {
            arr[i] -= n;
            if (arr[i] < 97)
            {
                arr[i] += 26;
            }
        }
        else if (arr[i] >= 65 && arr[i] <= 90)
        {
            arr[i] -= n;
            if (arr[i] < 65)
            {
                arr[i] += 26;
            }
        }
    }
    printf("%s", arr);

    return 0;
}