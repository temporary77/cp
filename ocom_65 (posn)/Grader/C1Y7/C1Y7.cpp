#include <iostream>
using namespace std;

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y)
    {
        printf("Invalid");
    }
    else
    {
        while (x <= y)
        {
            printf("%d ", x++);
        }
    }

    return 0;
}