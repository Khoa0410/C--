/*Given a date which is a string under the format YYYY-MM-DD
(in which YYYY is the year, MM is the month (the month í from 1 to 12),
and DD is the date (the date is from 1 to 31)). Extract the year, month and date.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    if(s.size() != 10) // Kiểm tra xâu có độ dài bằng 10 hay ko
    {
        cout << "INCORRECT";
        return 0;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(i == 4 || i == 7) // Kiểm tra vị trí 2 dấu '-'
        {
            if(s[i] != '-')
            {
                cout << "INCORRECT";
                return 0;
            }
        }
        else
        {
            if(s[i] < 48 || s[i] > 57) // Kiểm tra các vị trí còn lại có phải chữ số hay ko
            {
                cout << "INCORRECT";
                return 0;
            }
        }
    }

    // Tạo 3  biến lưu các giá trị năm, tháng, ngày
    int a1 = stoi(s.substr(0, 4));
    int a2 = stoi(s.substr(5, 2));
    int a3 = stoi(s.substr(8, 2));

    if(a2 > 12 || a3 > 31)
        cout << "INCORRECT";
    else
        cout << a1 << " " << a2 << " " << a3;
    return 0;
}