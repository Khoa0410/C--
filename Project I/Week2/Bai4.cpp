/* Given an integer n, write a program to generate all permutations of 1, 2, ..., n
in a lexicalgraphic order (elements of a permutation are separated by a SPACE character). */

#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

int a[MAX];

void print(int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

bool check(int k)
{
    for(int i = 0; i <= k - 1; i++)
        if(a[i] == a[k])    return false;
    return true;
}

void abc(int k, int n)
{
    for(int i = 1; i <= n; i++)
    {
        a[k] = i;
        if(check(k))
        {
            if(k == n - 1)  print(n);
            else    abc(k + 1, n);
        }
        else    continue;
    }
}
int main()
{
    int n;
    cin >> n;
    abc(0, n);
    return 0;
}