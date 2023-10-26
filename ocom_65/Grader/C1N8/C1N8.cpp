#include <iostream>
using namespace std;

int main()
{
    char n;
    scanf("%c", &n);
    if (n >= 48 && n <= 57)
    {
        printf("Number");
    }
    else if ((n >= 65 && n <= 90) || ((n >= 97) && n <= 122))
    {
        printf("Character");
    }
    else
    {
        printf("Special Characters");
    }
    return 0;
}