// Cho dãy số nguyên A1, A2, . . . , An với mỗi số nguyên Ai
// kiểm tra xem có số Aj nào bằng Ai hay không với j<i.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen(".inp", "r", stdin);

    int n;
    cin >> n;
    unordered_set<int> a; // tập hợp lưu các số đã xuất hiện
    
    for(int i = 0; i < n; i++)
    {
        int tmp;    cin >> tmp;

        // Kiểm tra xem số vừa nhập đã xuất hiện hay chưa
        if(a.count(tmp) > 0)
            cout << '1' << endl;
        else
        {
            cout << '0' << endl;
            a.insert(tmp); // Thêm số vào tập hợp các số đã xuất hiện
        }
    }
    return 0;
}