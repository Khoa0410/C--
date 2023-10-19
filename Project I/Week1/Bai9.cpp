/*Given a time moment which is a string under the format hh:mm:ss
(in which hh (0 <= hh <= 23) is the hour, mm (0 <= mm <= 59) is the minute,
and ss (0 <= ss <= 59) is the second). Convert this time moment in seconds (result = hh*3600 + mm*60 + ss).*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    if(s.size() != 8) // Kiểm tra xâu có độ dài = 8 hay ko
    {
        cout << "INCORRECT";
        return 0;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(i == 2 || i ==5)
        {
            if(s[i] != ':') // Kiểm tra vị trí 2 dấu :
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

    int a[3]; // Tạo mảng lưu các giá trị giờ, phút, giây
    a[0] = stoi(s.substr(0, 2));
    a[1] = stoi(s.substr(3, 2));
    a[2] = stoi(s.substr(6, 2));

    if((a[0] < 0) || (a[0] > 23) || (a[1] < 0) || (a[1] > 59) || (a[2] < 0) || (a[2] > 59))
    {
        cout << "INCORRECT";
        return 0;
    }
    else    cout << a[0] * 3600 + a[1] * 60 + a[2];
    return 0;
}