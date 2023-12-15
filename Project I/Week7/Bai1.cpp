// Bank Transaction

#include<bits/stdc++.h>
using namespace std;

// Cấu trúc của 1 giao dịch
struct transaction
{
    string from_account;
    string to_account;
    int money;
    string time_point;
    string atm;
};

vector<transaction> T; // Lưu các giao dịch
set<string> S; // Lưu các account trong các giao dịch
map<string, bool> visited; // Đánh dấu các tài khoản đã đc duyệt

// Tính số giao dịch
void number_transaction()
{
    cout << T.size() << endl;
}

// Tính tổng lượng tiền được giao dịch
void total_money_transaction()
{
    int sum = 0;
    for(auto e : T)
        sum += e.money;
    cout << sum << endl;
}

// Danh sách các tài khoản xuất hiện trong giao dịch
void list_sorted_accounts()
{
    for(auto e : T)
    {
        S.insert(e.from_account);
        S.insert(e.to_account);
    }

    //visited.resize(S.size() + 1);

    for(string tmp : S)
    {
        visited[tmp] = false; // cập nhật giá trị cho visited
        cout << tmp << ' '; // In danh sách các tài khoản
    }

    cout << endl;
}

// Tổng tiền được chuyển đi từ tài khoản t
void total_money_transaction_from(string t)
{
    int sum = 0;
    for(auto e : T)
        if(e.from_account == t)
            sum += e.money;
    cout << sum << endl;
}

// Kiểm tra transaction cycle
string acc;
int count_acc;
void inspect_cycle(string t, int k)
{
    
}

int main()
{
    freopen(".inp", "r", stdin);

    int count = 0; // Số lần nhập dấu '#'

    while(true)
    {
        // Nhập dữ liệu / truy vấn
        string s;   cin >> s;
        if(s == "#")
        {
            count ++;
            if(count == 2)  break;
        }

        // Nhập thông tin các giao dịch
        if(s[0] == 'T')
        {
            transaction tmp;
            tmp.from_account = s;
            cin >> tmp.to_account >> tmp.money >> tmp.time_point >> tmp.atm;
            T.push_back(tmp);
        }

        // Tính số giao dịch
        if(s == "?number_transactions")
            number_transaction();
        
        // Tính tổng lượng tiền được giao dịch
        if(s == "?total_money_transaction")
            total_money_transaction();

        // Danh sách các tài khoản
        if(s == "?list_sorted_accounts")
            list_sorted_accounts();

        // Tổng tiền được chuyển đi từ tài khoản t
        if(s == "?total_money_transaction_from")
        {
            string t;   cin >> t;
            total_money_transaction_from(t);
        }
        
        // Kiểm tra transaction cycle
        if(s == "inspect_cycle")
        {
            string t;
            int k;
            //cin >> t >> k;
            count_acc = 0;
        }
    }

    return 0;
}