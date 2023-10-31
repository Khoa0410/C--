/*Given a string s[1…k] which is a sequence of characters taken from {‘a’, . . ., ‘z’}.
Given a positive integer m, the hash code of s is defined by the formula:
H(s) =  (s[1]*256k-1 + s[2]*256k-2 + . . . + s[k]*2560 ) mod m  (the contant integer m is a parameter)
Given a sequence of strings k1, k2, …, kn, compute the corresponding hash codes*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
int modun[200]; // modun[i] = 256^i % m

int hash_code(string s)
{
    int tmp = 0;
    int h = s.size();

    for(int i = 0; i < h; i++)
    {
        tmp += s[i] * modun[h - i - 1];
        tmp %= m;
    }
    return tmp;
}

int main()
{
    //freopen(".inp", "r", stdin);
    
    cin >> n >> m;

    // Tính giá trị cho mảng modun[]
    modun[0] = 1;
    for(int i = 1; i < 200; i++)
    {
        modun[i] = modun[i - 1] * 256;
        modun[i] = modun[i] % m;
    }

    // Nhập các xâu và tính hash code
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cout << hash_code(s) << "\n";
    }

    return 0;
}