// Given two integer n and M. Write a program that generates all ordered
// collection (X1, X2, ..., Xn) such that: X1 + X2 + . . . + Xn = M

#include<bits/stdc++.h>
using namespace std;

void abc(int n, int m, vector<int>& a, int sum)
{
    // in ra bộ nghiệm
    if(n == 0 && sum == m)
    {
        for(int i = 0; i < a.size(); i++)
            cout << a[i] << ' ';
        cout << endl;
        return;
    }

    for(int i = 1; i <= m - sum; i++)
    {
        a.push_back(i);
        abc(n - 1, m, a, sum + i);
        a.pop_back();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    abc(n, m, a, 0);
    return 0;
}