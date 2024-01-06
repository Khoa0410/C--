#include <bits/stdc++.h>
#include <fcntl.h>
using namespace std;
int main(int argc, char* argv[]) {
    cout << "dcm ngu vl: ";
    ifstream file(".inp"); // Đọc dữ liệu đầu vào từ file .inp
    if (!file) {
        std::cout << "Không thể mở file .inp" << std::endl;
        return 1; // Thoát chương trình nếu không thể mở file
    }

    if (argc > 1) {
        std::string a = argv[1];
        std::cout << "Biến a: " << a << std::endl;
        int x = a[0] - '0';
        std::cout << x << std::endl;
        
    } else {
        std::cout << "Không có dữ liệu đầu vào từ cmd." << std::endl;
    }
    int tmp;
        file >> tmp;
        cout << "dcm ngu vl: " << tmp << endl;
    return 0;
}
