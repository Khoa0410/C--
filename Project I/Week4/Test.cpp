#include <bits/stdc++.h>

using namespace std;
int n, m, a[205]; // a[i] = 256^i % m
string k[100005];

int hashCode(string s)
{
    int hash = 0, len = s.length();
    for (int i = 0; i < len; ++i)
    {
        hash += s[i] * a[len - 1 - i];
        hash %= m;
    }
    return hash;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
    }
    a[0] = 1;
    for (int i = 1; i <= 200; ++i)
    {
        a[i] = a[i - 1] * 256;
        a[i] %= m;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << hashCode(k[i]) << "\n";
    }
}