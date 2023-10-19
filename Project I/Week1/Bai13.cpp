// Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) of this Text

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen(".inp", "r", stdin);

    string s;
    int count = 0;

    while(getline(cin, s))
    {
        s = ' ' + s;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i - 1] == ' ' && s[i] != ' ')
                count ++;
        }
    }

    cout << count;

    return 0;
}