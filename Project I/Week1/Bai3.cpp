/* Hiện tại giá điện đang được tính theo bậc thang gồm 6 mức (mức điều chỉnh từ 04/05/2023),
với giá thấp nhất (bậc 1) là 1.728VND và giá bậc cao nhất là 3.015 VND.
Tuy nhiên EVN đang đề xuất một cách tính giá điện bậc thang mới chỉ gồm 5 mức như hinh dưới,
giá thấp nhất (bậc 1) khoảng 1.728 đồng một kWh và cao nhất (bậc 5) là 3.457 đồng một kWh.
Bậc	Biểu giá hiện hành	Phương án 5 bậc
  	Mức sử dụng	Giá (*)	Mức sử dụng	Giá
1	0-50 kWh	1.728	0-100 kWh	1.728
2	51-100 kWh	1.786	101-200 kWh	2.074
3	101-200 kWh	2.074	201-400 kWh	2.612
4	201-300 kWh	2.612	401-700 kWh	3.111
5	301-400 kWh	2.919	701 kWh trở lên	3.457
6  	401 kWh trở lên	3.015		
(*) Giá chưa bao gồm thuế VAT

Hãy xây dựng chương trình nhập vào số kwh điện của một hộ tiêu thụ và so sánh
xem theo bảng giá mới đang lấy ý kiến thì tiền điện tiêu thụ của hộ đó sẽ tăng thêm hay giảm đi bao nhiêu.*/

#include<bits/stdc++.h>
using namespace std;

double gia1(int x) // giá theo thang 6 mức
{
    if(x <= 50)     
        return x * 1.728;
    if(x <= 100)    
        return 50 * 1.728 + (x - 50) * 1.786;
    if(x <= 200)    
        return 50 * 1.728 + 50 * 1.786 + (x -100) * 2.074;
    if(x <= 300)
        return 50 * 1.728 + 50 * 1.786 + 100 * 2.074 + (x - 200) * 2.612;
    if(x <= 400)
        return 50 * 1.728 + 50 * 1.786 + 100 * 2.074 + 100 * 2.612 + (x - 300) * 2.919;
    return 50 * 1.728 + 50 * 1.786 + 100 * 2.074 + 100 * 2.612 + 100 * 2.919 + (x - 400) * 3.015;
}

double gia2(int x) // giá theo thang 5 mức
{
    if(x <= 100)
        return x * 1.728;
    if(x <= 200)
        return 100 * 1.728 + (x - 100) * 2.074;
    if(x <= 400)
        return 100 * 1.728 + 100 * 2.074 + (x - 200) * 2.612;
    if(x <= 700)
        return 100 * 1.728 + 100 * 2.074 + 200 * 2.612 + (x - 400) * 3.111;
    return 100 * 1.728 + 100 * 2.074 + 200 * 2.612 + 300 * 3.111 + (x - 700) * 3.457;    
}
int main()
{
    int x;
    cin >> x;
    double delta = (gia2(x) - gia1(x)) * 1.1 * 1000;
    cout << fixed << setprecision(2) << delta;
    return 0;
}