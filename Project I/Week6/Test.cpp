#include <bits/stdc++.h>

using namespace std;

int cnt, u, v, k, cnt1;
int visited[100009];
long long money, Tmoney, Sum[100009];
vector < int > a[100009];
map < string, int > Map;
string facc, tacc, Time, Bank, quest;

int dfs(int t, int u, int sl)
{
    if(sl == k)
    {
        for(int v:a[u])
            if(v == t)
                return 1;
        return 0;
    }

    for(int v:a[u])
        if(visited[v] == 0)
        {
            visited[v] = 1;
            if(dfs(t, v, sl +1))
                return 1;
            visited[v] = 0;
        }

    return 0;
}
int main()
{
    freopen(".inp", "r", stdin);

    while(1)
    {
        cin >> facc;
        if(facc == "#")
            break;

        cin >> tacc >> money >> Time >> Bank;
        if(Map[facc] == 0)
            cnt++, Map[facc] = cnt;
        if(Map[tacc] == 0)
            cnt++, Map[tacc] = cnt;
        cnt1++;
        Tmoney+= money;

        u = Map[facc]; v = Map[tacc];
        Sum[u]+= money;
        a[u].push_back(v);
    }

    while(1)
    {
        cin >> quest;
        if(quest == "#")
            break;

        if(quest == "?number_transactions")
            cout << cnt1 << '\n';

        if(quest == "?total_money_transaction")
            cout << Tmoney << '\n';

        if(quest == "?list_sorted_accounts")
        {
            for(auto it=Map.begin(); it!=Map.end(); it++)
                cout << it->first << ' ';
            cout << '\n';
        }

        if(quest == "?total_money_transaction_from")
        {
            cin >> facc;
            u = Map[facc];
            cout << Sum[u] << '\n';
        }

        if(quest == "?inspect_cycle")
        {
            cin >> facc >> k;
            u = Map[facc];
            memset(visited, 0, sizeof(visited));
            visited[u] = 1;
            cout << (dfs(u, u, 1)) << '\n';
        }
    }
    
    return 0;
}