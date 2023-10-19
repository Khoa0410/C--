// Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int d = b * b - 4 * a * c;
    if(d < 0)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        if(d == 0)
        {
            double x0 = -b / (2 * a);
            cout << fixed << setprecision(2) << x0;            
        }
        else
        {
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);
            cout << fixed << setprecision(2) << x2;
            cout << " ";            
            cout << fixed << setprecision(2) << x1;            
        }
    }
    return 0;
}