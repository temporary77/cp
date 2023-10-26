#include <iostream>
using namespace std;

int main()
{
    int scr;
    scanf("%d", &scr);
    if (scr > 100)
    {
        printf("Error");
    }
    else if (scr >= 80)
    {
        printf("A");
    }
    else if (scr >= 70)
    {
        printf("B");
    }
    else if (scr >= 60)
    {
        printf("C");
    }
    else if (scr >= 50)
    {
        printf("D");
    }
    else if (scr >= 0)
    {
        printf("F");
    }
    else
    {
        printf("Error");
    }

    return 0;
}