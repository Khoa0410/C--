/*Given a string s[1…k] which is a sequence of characters taken from {‘a’, . . ., ‘z’}.
Given a positive integer m, the hash code of s is defined by the formula:
H(s) =  (s[1]*256k-1 + s[2]*256k-2 + . . . + s[k]*2560 ) mod m  (the contant integer m is a parameter)
Given a sequence of strings k1, k2, …, kn, compute the corresponding hash codes*/

#include<bits/stdc++.h>
using namespace std;

// Hàm chia lấy dư của a mũ b chia cho m
int modulo(int a, int b, int m)
{
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (1LL * res * a) % m;
        }
        a = (1LL * a * a) % m;
        b /= 2;
    }
    return res;
}

int hash_code(string s, int m)
{
    long long tmp = 0;
    for(int i = 0; i < s.size(); i++)
    {
        tmp = tmp + 1LL * s[i] * modulo(256, s.size() - i - 1, m);
        tmp = tmp % m;
    }
    return tmp;
}

int main()
{
    //freopen(".inp", "r", stdin);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cout << hash_code(s, m) << endl;
    }

    return 0;
}