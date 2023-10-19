//Given a sequence of integer a1, a2, ..., an. Count the number of odd elements and even elements of the sequence.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, count = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] % 2 != 0)   count ++;
    }
    cout << count << " " << n - count;
    return 0;
}