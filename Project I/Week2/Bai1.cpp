/* Given two positive integers k and n.
Compute C(k,n) which is the number of ways to select k objects from a given set of n objects. */

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000;

vector< vector<long long> > to_hop; // Mảng lưu các giá trị tổ hợp

void tinh_to_hop()
{
    to_hop.resize(MAX + 1, vector<long long>(MAX + 1, 0));

    for(int i = 0; i <= MAX; i++)
    {
        to_hop[0][i] = 1; // k = 0 => C(0, n) = 1
        to_hop[i][i] = 1; // k = n => C(k, n) = 1
    }

    for(int i = 1; i <= MAX; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            to_hop[j][i] = (to_hop[j - 1][i - 1] + to_hop[j][i - 1]) % 1000000007; // 10^9 + 7
        }
    }
}

long long kq(int k, int n)
{
    return to_hop[k][n];
}

int main()
{
    tinh_to_hop();
    int k, n;
    cin >> k >> n;
    cout << kq(k, n);
    return 0;
}