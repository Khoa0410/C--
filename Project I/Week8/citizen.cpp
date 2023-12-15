#include <bits/stdc++.h>
using namespace std;

string code, query;
unordered_map<string, int> dobPeopleMap;
int numOfPeople = 0, bornBefore[1100000], father[100005], mother[100005], person[100005];

int parseToDate(string date)
{
    return ((date[0] - 48) * 1000 + (date[1] - 48) * 100 + (date[2] - 48) * 10 + (date[3] - 48)) * 365 + ((date[5] - 48) * 10 + (date[6] - 48)) * 30 + (date[8] - 48) * 10 + (date[9] - 48);
}

int codeToInt(string code)
{
    int temp = 0;
    for (int i = 0; i < code.length(); ++i)
    {
        temp = temp * 10 + (code[i] - '0');
    }
    return temp;
}

void prefixSum()
{
    for (int i = 1; i <= 1100000; ++i)
        bornBefore[i] += bornBefore[i - 1];
}

int mostAncestor(int code)
{
    if (!code)
        return 0;
    int momSide = mostAncestor(mother[code]);
    int dadSide = mostAncestor(father[code]);
    return max(momSide, dadSide) + 1;
}

int main()
{
    freopen(".inp", "r", stdin);
    
    cin >> code;
    while (code != "*")
    {
        string dob, dadCode, momCode, regionCode;
        char isAlive;
        cin >> dob >> dadCode >> momCode >> isAlive >> regionCode;

        numOfPeople++;

        dobPeopleMap[dob]++;

        father[codeToInt(code)] = codeToInt(dadCode);
        mother[codeToInt(code)] = codeToInt(momCode);
        person[numOfPeople] = codeToInt(code);

        bornBefore[parseToDate(dob)]++;

        cin >> code;
    }
    prefixSum();
    cin >> query;
    while (query != "***")
    {
        if (query == "NUMBER_PEOPLE")
            cout << numOfPeople;
        else if (query == "NUMBER_PEOPLE_BORN_AT")
        {
            string date;
            cin >> date;
            cout << dobPeopleMap[date];
        }
        else if (query == "MOST_ALIVE_ANCESTOR")
        {
            string code;
            cin >> code;
            cout << mostAncestor(codeToInt(code)) - 1;
        }
        else if (query == "NUMBER_PEOPLE_BORN_BETWEEN")
        {
            string fromDate, toDate;
            cin >> fromDate >> toDate;
            int t1 = parseToDate(fromDate), t2 = parseToDate(toDate);
            cout << bornBefore[t2] - bornBefore[t1 - 1];
        }
        else if (query == "MAX_UNRELATED_PEOPLE")
        {
            int k = 0, j = 0;
            for (int i : person)
            {
                if (i)
                {
                    if (mostAncestor(i) % 2 == 0)
                        k++;
                    else
                        j++;
                }
            }
            cout << max(k, j);
        }
        cout << "\n";

        cin >> query;
    }
}