#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> mySet = {3, 1, 4, 1, 5, 9};  // Sử dụng set với các giá trị ngẫu nhiên

    // Duyệt qua các phần tử của set bằng iterator
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << endl;  // In ra giá trị của phần tử
    }

    return 0;
}