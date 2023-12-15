//Problem: Week 7 - atm Transaction

#include <bits/stdc++.h>
using namespace std;

int in_dex, u, v, k, number_transactions;
int visited[100009];// Đánh dấu các account đã được duyệt
long long money;
long long sum_money; // Tổng tiền của các giao dịch
long long sum_money_from[100009]; // Tổng tiền đã chuyển đi của các account
vector<int> a[100009]; // a[i] là thứ tự các to_account của account có thứ tự i
map<string, int> Acc; // Lưu thứ tự của các account
string from_account, to_account, time_point, atm, query;

// Sử dụng duyệt đồ thị theo chiều sâu để kiểm tra inspect_cycle của account có thứ tự x
int inspect_cycle(int x, int y, int s)
{
    if(s == k)
    {
        for(int e : a[y])
            if(e == x)  return 1;
        return 0;
    }

    for(int e : a[y])
        if(visited[e] == 0)
        {
            visited[e] = 1;
            if(inspect_cycle(x, e, s + 1))
                return 1;
            visited[e] = 0;
        }

    return 0;
}

int main()
{
    //freopen(".inp", "r", stdin);

    // Nhập data block
    while(true)
    {
        cin >> from_account;

        if(from_account == "#")     break;

        cin >> to_account >> money >> time_point >> atm;

        if(Acc[from_account] == 0)
            in_dex++, Acc[from_account] = in_dex;
        if(Acc[to_account] == 0)
            in_dex++, Acc[to_account] = in_dex;

        number_transactions ++;
        sum_money += money;

        u = Acc[from_account]; v = Acc[to_account];
        sum_money_from[u] += money;
        a[u].push_back(v);
    }

    // Nhập query block
    while(true)
    {
        cin >> query;

        if(query == "#")    break;

        if(query == "?number_transactions")
            cout << number_transactions << endl;

        if(query == "?total_money_transaction")
            cout << sum_money << endl;

        if(query == "?list_sorted_accounts")
        {
            for(auto it = Acc.begin(); it != Acc.end(); it++)
                cout << it->first << ' ';
            cout << endl;
        }

        if(query == "?total_money_transaction_from")
        {
            cin >> from_account;
            u = Acc[from_account];
            cout << sum_money_from[u] << endl;
        }

        if(query == "?inspect_cycle")
        {
            cin >> from_account >> k;
            u = Acc[from_account];
            memset(visited, 0, sizeof(visited));
            visited[u] = 1;
            cout << inspect_cycle(u, u, 1) << endl;
        }
    }
    
    return 0;
}