// Given a positive integer n, find all integer having 3 digits which is divisible by n.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int l = 100 / n;
    int r = 1000 / n;
    if(l * n < 100)     l++;
    if(r * n == 1000)   r--;
    for(int i = l; i <= r; i++)
    {
        cout << i * n << " ";
    }
    return 0;
}