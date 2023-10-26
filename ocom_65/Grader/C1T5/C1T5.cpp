#include <bits/stdc++.h>
using namespace std;

int main()
{
    double d, y, t, cost;
    scanf("%lf%lf%lf%lf", &d, &y, &t, &cost);
    if (int(y) % 400 == 0)
    {
        y = 1;
    }
    else if (int(y) % 100 == 0)
    {
        y = 0;
    }
    else if (int(y) % 4 == 0)
    {
        y = 1;
    }
    else
    {
        y = 0;
    }
    cost *= d;
    if (y == 1)
    {
        if (d > 7)
        {
            d = 0.1;
        }
        else
        {
            d = 0.05;
        }
        if (t > 1830)
        {
            t = 0.1;
        }
        else if (t > 1330)
        {
            t = 0.15;
        }
        else if (t > 1130)
        {
            t = 0.2;
        }
        else if (t >= 930)
        {
            t = 0.3;
        }
        else
        {
            t = 0.1;
        }
    }
    else
    {
        if (d > 7)
        {
            d = 0.05;
        }
        else
        {
            d = 0;
        }
        if (t > 1830)
        {
            t = 0;
        }
        else if (t > 1330)
        {
            t = 0.05;
        }
        else if (t > 1130)
        {
            t = 0.1;
        }
        else if (t >= 930)
        {
            t = 0.15;
        }
        else
        {
            t = 0;
        }
    }
    cost -= (d + t) * cost;
    printf("%.2lf", cost);
    return 0;
}