/*Given undirected graph G = (V,E) in which V = {1, 2, ..., n}
is the set of nodes, and E is the set of m edges.
Write a program that computes the sequence of nodes visited using a BFS algorithm
(the nodes are considered in a lexicographic order)*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G; // G[u][] là các đỉnh kề đỉnh u

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

// Duyệt đồ thị theo chiều sâu
vector<int> bfs(const vector<vector<int>> &G)
{
    int V = G.size();               // Số đỉnh của đồ thị
    vector<bool> visited(V, false); // Mảng đánh dấu các đỉnh đã được duyệt, khởi tạo giá trị false
    queue<int> Q;                   // Hàng đợi lưu các đỉnh
    vector<int> visited_kq;         // Danh sách các đỉnh đã được thăm

    for (int i = 1; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            Q.push(i);

            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                visited_kq.push_back(u); // Đưa đỉnh u vào danh sách các đỉnh đã thăm

                // Thăm các đỉnh kề đỉnh u
                for (int v : G[u])
                {
                    if (!visited[v])
                    {
                        visited[v] = true;
                        Q.push(v);
                    }
                }
            }
        }
    }

    return visited_kq;
}

int main()
{
    freopen(".inp", "r", stdin);

    input();
    vector<int> visited_kq = bfs(G);

    // In ra kết quả
    for (int v : visited_kq)
        cout << v << ' ';

    return 0;
}