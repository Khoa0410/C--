// Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 20;

int s[MAX];

void print(int n)
{
    for(int i = 0; i < n; i++)
        cout << s[i];
    cout << endl;
}

void abc(int k, int n)
{
    for(int i = 0; i <= 1; i++)
    {
        s[k] = i;
        if(k == n - 1)  print(n);
        else    abc(k + 1, n);
    }
}

int main()
{
    //freopen(".inp", "r", stdin);
    int n;
    cin >> n;
    abc(0, n);
    return 0;
}