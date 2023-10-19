/* Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:
find-max: return the maximum element of the given sequence
find-min: return the minimum element of the given sequence 
sum: return the sum of the elements of the given sequence 
find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j) */

#include<bits/stdc++.h>
using namespace std;

int find_max(int l, int r, int a[]) // Hàm tìm max trong đoạn l, r
{
    int tmp = -1000;
    for(int i = l - 1; i <= r - 1; i++)
        if(a[i] > tmp)  tmp = a[i];
    return tmp;
}

int find_min(int l, int r, int a[]) // Hàm tìm min trong đoạn l, r
{
    int tmp = 1000;
    for(int i = l - 1; i <= r - 1; i++)
        if(a[i] < tmp)  tmp = a[i];
    return tmp;
}

int main()
{
    //freopen(".inp", "r", stdin);
    int n, sum = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    string s;
    while(true)
    {
        cin.ignore();
        cin >> s;
        if(s == "***")  break;
        if(s == "find-max")     cout << find_max(1, n, a) << endl;
        if(s == "find-min")     cout << find_min(1, n, a) << endl;
        if(s == "sum")          cout << sum << endl;
        if(s == "find-max-segment")
        {
            int b[2];
            cin >> b[0] >> b[1];
            cout << find_max(b[0], b[1], a) << endl;
        }
    }

    return 0;
}