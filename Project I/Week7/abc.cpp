#include <bits/stdc++.h>

using namespace std;

int cnt, Scnt, Ccnt, sID, cID;
long long Price, SPrice;
map < string, int > Smap, Cmap;
map < pair < int, int > , long long > Map;
int ro_shop[100009];
pair < int, int > x;
string cusID, proID, SID, Time, eTime, sTime, quest;
long long a[100009];

int cal(string s)
{
    int res = 0;
    int hh, mm, ss;
    hh = (s[0] - 48) * 10 + s[1] - 48;
    mm = (s[3] - 48) * 10 + s[4] - 48;
    ss = (s[6] - 48) * 10 + s[7] - 48;

    return hh * 3600 + mm * 60 + ss +1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(".inp", "r", stdin);
    while(1)
    {
        cin >> cusID;
        if(cusID == "#")
            break;

        cin >> proID >> Price >> SID >> Time;
        cnt++;
        SPrice+= Price;

        if(Smap[SID] == 0)
            Scnt++, Smap[SID] = Scnt;
        sID = Smap[SID];
        ro_shop[sID]+= Price;

        if(Cmap[cusID] == 0)
            Ccnt++, Cmap[cusID] = Ccnt;
        cID = Cmap[cusID];
        x = {sID, cID};
        Map[x]+= Price;

        a[cal(Time)]+= Price;
    }

    for(int i=1; i<=86400; ++i)
        a[i]+= a[i -1];

    while(1)
    {
        cin >> quest;

        if(quest == "#")
            break;

        if(quest == "?total_number_orders")
            cout << cnt << '\n';

        if(quest == "?total_revenue")
            cout << SPrice << '\n';

        if(quest == "?revenue_of_shop")
        {
            cin >> SID;
            sID = Smap[SID];
            cout << ro_shop[sID] << '\n';
        }

        if(quest == "?total_consume_of_customer_shop")
        {
            cin >> cusID >> SID;
            sID = Smap[SID];
            cID = Cmap[cusID];
            x = {sID, cID};
            cout << Map[x] << '\n';
        }

        if(quest == "?total_revenue_in_period")
        {
            cin >> sTime >> eTime;
            cout << a[cal(eTime)] - a[cal(sTime) -1] << '\n';
        }
    }
    return 0;
}