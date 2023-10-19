/*Given a fibonacci sequence a[0], a[1], a[2], ... in which: 
a[0] = 0, a[1] = 1, a[n] = a[n-1] + a[n-2], for all n >= 2
Given  positive integer n, compute a[n-1].*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
long long a[MAX]; // mảng a lưu dãy fibonanci

void fibo(int MAX)
{
    for(int i = 0; i <= MAX; i++)
    {
        if(i == 0)  a[i] = 0;
        if(i == 1)  a[i] = 1;
        if(i > 1)   a[i] = a[i - 1] + a[i - 2];
    }
}

int main()
{
    fibo(MAX);
    int n;
    cin >> n;
    cout << a[n - 1];
    return 0;
}