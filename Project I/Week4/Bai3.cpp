/*
A database contains a sequence of key k1, k2, ..., kn which are strings (1<=n<=100000).
Perform a sequence of actions of two kinds:
· find k: find and return 1 if k exists in the database, and return 0, otherwise
· insert k: insert a key k into the database and return 1 if the insertion is successful
(k does not exist in the database) and return 0 if the insertion is failed (k exists in the database)
*/

#include<bits/stdc++.h>
using namespace std;

unordered_set<string> s;

int main()
{
    //freopen(".inp", "r", stdin);

    while(true)
    {
        string k;   cin >> k;
        if(k == "*")    continue;
        if(k == "***")  break;

        // Thực hiện tìm kiếm khóa khi nhập vào "find"
        if(k == "find")
        {
            string key;     cin >> key;
            if(s.count(key) > 0)    cout << '1' << endl;
            else                    cout << '0' << endl;
        }

        // Thực hiện chèn khóa khi nhập vào "insert"
        if(k == "insert")
        {
            string key;     cin >> key;
            
            if(s.count(key) > 0)
                cout << '0' << endl;
            else
            {
                cout << '1' << endl;
                s.insert(key);
            }
        }

        s.insert(k); // Thêm khóa vào danh sách
    }

    return 0;
}