#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n >= 1000)
    {
        printf("100");
    }
    else if (n >= 0)
    {
        printf("0");
    }
    else
    {
        printf("Error");
    }

    return 0;
}