//Given an integer n, print numbers from 1 to n and its squares.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cout << i << " " << i * i << endl;
    }
    return 0;
}