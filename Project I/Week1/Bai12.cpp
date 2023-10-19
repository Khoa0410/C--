/* Given a sequence of integers a1, a2, . . ., an.
A k-subsequence is define to be a sequence of k consecutive elements: ai, ai+1, . . ., ai+k-1.
The weight of a k-subsequence is the sum of its elements.
Given positive integers k and m.
Compute the number Q of k-subsequences such that the weight is even. */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, sum = 0, count = 0;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    for(int i = 0; i < k; i++) // tính tổng k số đầu
        sum += a[i];
    if(sum % 2 == 0)    count ++;
    
    for(int i = 1; i < n - k + 1; i++)
    {
        sum = sum - a[i - 1] + a[i - 1 + k];
        if(sum % 2 == 0)    count ++;
    }

    cout << count;

    return 0;
}