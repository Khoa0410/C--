/*Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M.
Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen(".inp", "r", stdin);

    set<int> a; // Dãy các số đầu vào
    int n, m;
    int count = 0; // Số các cặp thỏa mãn
    cin >> n >> m;

    // Lưu các số vào dãy a
    for(int i = 0; i < n; i++)
    {
        int num;    cin >> num;
        a.insert(num);
    }

    for(auto it = a.begin(); it != a.end(); it++)
    {
        int num = m - *it;
        if(a.count(num) > 0)    count ++;
    }

    cout << count / 2; // Do các cặp bị lặp nên cần chia 2

    return 0;
}