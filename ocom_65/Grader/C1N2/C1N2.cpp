#include <iostream>
using namespace std;

int main()
{
    double w, h;
    scanf("%lf %lf", &w, &h);
    printf("%.2lf\n%.2lf\n%.2lf", w, h, w / h / h);
    return 0;
}