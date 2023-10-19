/*Perform a sequence of operations over a queue, each element is an integer:
PUSH v: push a value v into the queue
POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)*/

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
        cout << a[s] << endl;
        s ++;
    }
}

int main()
{
    //freopen(".inp", "r", stdin);

    int queue[1000], start = 0, end = -1;
    string s;

    while(true)
    {
        cin >> s;

        if(s == "#")    break;

        if(s == "PUSH")
        {
            int tmp;
            cin >> tmp;
            PUSH(queue, start, end, tmp);
        }
        
        if(s == "POP")
        {
            POP(queue, start, end);
        }

    }
    return 0;
}