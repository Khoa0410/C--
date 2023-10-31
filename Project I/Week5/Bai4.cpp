// Given an undirected graph G = (V,E). Write a program to check if G is a Hamiltonian graph.

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G; // G[u][] là các đỉnh kề đỉnh u
vector<bool> visited;  // Mảng đánh dấu đỉnh đã được thăm hay chưa
bool is_hamilton;      // Biến trả về kết quả đồ thị có chu trình hamilton không

// Nhập dữ liệu đầu vào và xây dưng mảng G lưu các đỉnh
void input()
{
    cin >> n >> m;
    G.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // Sắp xếp giá trị các hàng trong G theo thứ tự tăng dần
    for (int i = 1; i < n; i++)
        sort(G[i].begin(), G[i].end());
}

void hamilton(int u, vector<int> &visit, bool &is_hamilton)
{
    if (!visited[u])
    {
        visited[u] = true;
        visit.push_back(u);

        // Điều kiện dừng
        if (visit.size() == n)
        {
            int tmp1 = visit.back();
            int tmp2 = visit[0];
            for (int i = 1; i <= n; i++)
            {
                if (G[tmp2][i] == tmp1)
                {
                    is_hamilton = true;
                    return;
                }
            }
        }

        for (int i : G[u])
            hamilton(i, visit, is_hamilton);

        // Thực hiện quay lui
        visit.pop_back();
        visited[u] = false;
    }
}

int main()
{
    //freopen(".inp", "r", stdin);

    int t;
    cin >> t;

    while (t--)
    {
        input();

        int V = G.size();
        visited.resize(V, false);
        is_hamilton = false;
        vector<int> visit; // Mảng lưu các đỉnh đã được thăm

        // Kiểm tra chu trình hamilton với từng đỉnh là đỉnh bắt đầu
        for (int i = 1; i <= n; i++)
            hamilton(i, visit, is_hamilton);

        if (is_hamilton)
            cout << '1' << endl;
        else
            cout << '0' << endl;
    }

    return 0;
}