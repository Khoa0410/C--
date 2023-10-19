/*Perform a sequence of operations over a stack, each element is an integer:
PUSH v: push a value v into the stack
POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)*/

#include<bits/stdc++.h>
using namespace std;

void PUSH(int a[], int& s, int& e, int num)
{
    e ++;
    a[e] = num;
}

void POP(int a[], int& s, int& e)
{
    if(s > e)   cout << "NULL" << endl;
    else
    {
        cout << a[e] << endl;
        e --;
    }
}

int main()
{
    //freopen(".inp", "r", stdin);

    int stack[1000], start = 0, end = -1;
    string s;

    while(true)
    {
        cin >> s;

        if(s == "#")    break;

        if(s == "PUSH")
        {
            int tmp;
            cin >> tmp;
            PUSH(stack, start, end, tmp);
        }
        
        if(s == "POP")
        {
            POP(stack, start, end);
        }

    }
    return 0;
}