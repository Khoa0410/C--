//Problem: Week 7 - Analyze sales order of an e-commerce company

#include <bits/stdc++.h>
using namespace std;

// Cấu trúc lưu 1 đơn hàng
struct order
{
    string cus_ID, prod_ID, shop_ID, time;
    int price;
    int s_time; // Thời gian tính theo giây
};

vector<order> Order;
map<string, int> shop_revenue; // Doanh thu của các cửa hàng
map< pair<string, string>, int> total_consume_of_customer_shop; // Tổng tiền 1 shop thu đc từ 1 khách hàng

// Đổi time thành giây
int stime(string time)
{
    int h, m, s;
    h = (time[0] - 48) * 10 + time[1] - 48;
    m = (time[3] - 48) * 10 + time[4] - 48;
    s = (time[6] - 48) * 10 + time[7] - 48;

    return h * 3600 + m * 60 + s + 1;
}

// Tổng doanh thu trong khoảng thời gian t1 đến t2
int total_revenue_in_period(int t1, int t2)
{
    int sum = 0;
    for(auto e : Order)
    {
        if(e.s_time >= t1 && e.s_time <= t2)
            sum += e.price;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(".inp", "r", stdin);

    int total_revenue = 0; // Tổng doanh thu của công ty
    
    // Nhập khối data
    while(true)
    {
        string s;   cin >> s;
        if(s == "#")    break;

        order tmp;
        tmp.cus_ID = s;
        cin >> tmp.prod_ID >> tmp.price >> tmp.shop_ID >> tmp.time;
        tmp.s_time = stime(tmp.time);
        Order.push_back(tmp);
        total_revenue += tmp.price;
        shop_revenue[tmp.shop_ID] += tmp.price;
        total_consume_of_customer_shop[make_pair(tmp.cus_ID, tmp.shop_ID)] += tmp.price;
    }

    // Nhập khối query
    while(true)
    {
        string s;   cin >> s;
        if(s == "#")    break;

        if(s == "?total_number_orders")
            cout << Order.size() << '\n';

        if(s == "?total_revenue")
            cout << total_revenue << '\n';

        if(s == "?revenue_of_shop")
        {
            string shop;    cin >> shop;
            cout << shop_revenue[shop] << '\n';
        }

        if(s == "?total_consume_of_customer_shop")
        {
            string cus, shop;
            cin >> cus >> shop;
            cout << total_consume_of_customer_shop[make_pair(cus, shop)] << '\n';
        }

        if(s == "?total_revenue_in_period")
        {
            string start, end;
            cin >> start >> end;
            int tmp1 = stime(start);
            int tmp2 = stime(end);
            cout << total_revenue_in_period(tmp1, tmp2) << '\n';
        }
    }

    return 0;
}