/*Given a string containing only characters (, ), [, ] {, }.
Write a program that checks whether the string is correct in expression.
Example
 ([]{()}()[]): correct
 ([]{()]()[]): incorrect*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen(".inp", "r", stdin);

    stack<char> s;
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++)
    {
        // Nếu gặp dấu đóng ngoặc thì thêm vào stack
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);

        // Nếu gặp dấu mở ngoặc
        if(str[i] == ')')
        {
            if(s.empty()) // Nếu stack rỗng thì in '0'
            {
                cout << '0';
                return 0;
            }
            else
            {
                // Nếu gặp dấu mở ngoặc tướng ứng thì lấy ra khỏi stack
                if(s.top() == '(')
                    s.pop();
                else    break; // Nếu dấu mở ngoặc không tương ứng thì dừng vòng lặp
            }
        }
        
        if(str[i] == ']')
        {
            if(s.empty())
            {
                cout << '0';
                return 0;
            }
            else
            {
                if(s.top() == '[')
                    s.pop();
                else    break; 
            }
        }

        if(str[i] == '}')
        {
            if(s.empty())
            {
                cout << '0';
                return 0;
            }
            else
            {
                if(s.top() == '{')
                    s.pop();
                else    break; 
            }
        }
    }

    if(s.empty())   cout << '1';
    else    cout << '0';

    return 0;
}