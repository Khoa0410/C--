/*Given a TEXT, write a program that converts the TEXT to upper-case. */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen(".inp", "r", stdin);
    
    string text;
    int count = 0;

    while(getline(cin, text))
    {
        for(int i = 0; i < text.size(); i++)
        {
            if(text.at(i) > 96 && text.at(i) < 123)
            {
                text.at(i) = text.at(i) - 32;
            }
        }
        cout << text << endl;
    }

    return 0;
}