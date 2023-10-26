#include <bits/stdc++.h>
using namespace std;

int main()
{
    char arr[1000] = {};
    scanf("%[^\n]", arr);
    for (int i = 1; i < 1000; ++i)
    {
        if ((arr[i] == 'p' && arr[i - 1] == arr[i + 1]) && (arr[i - 1] == 'a' || arr[i - 1] == 'e' || arr[i - 1] == 'i' || arr[i - 1] == 'o' || arr[i - 1] == 'u'))
        {
            arr[i] = '\0';
            arr[i + 1] = '\0';
        }
    }
    for (int i = 0; i < 1000; ++i)
    {
        printf("%c", arr[i]);
    }
    return 0;
}