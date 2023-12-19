#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100];
    for(int i = 100; i >= 1; i--)
        a[100 - i] = i;
    for(int i = 0; i < 100; i++)
        cout << a[i] << ' ';
    return 0;
}