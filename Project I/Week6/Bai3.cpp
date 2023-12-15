/*Given a network G = (V, E) which is a directed weighted graph.
Node s is the source and node t is the target.
c(u,v) is the c of the arc (u,v). Find the maximum f on G.*/

#include <bits/stdc++.h>
using namespace std;

// Cấu trúc 1 cạnh của đồ thị
struct canh
{
    int u, v; // Đỉnh đầu và đỉnh cuối của cạnh
    int c; // Sức chứa của cạnh
    int f; // Lưu lượng hiện tại của cạnh
    int r; // Sức chứa còn lại của cạnh

    canh(int u, int v, int c) : u(u), v(v), c(c), f(0), r(c) {}
};

// Hàm tìm dòng cực đại bằng thuật toán Edmonds-Karp
int max_flow(vector<vector<canh>>& graph, int s, int t)
{
    int V = graph.size(); // Số đỉnh của đồ thị
    vector<vector<int>> r(V, vector<int>(V, 0)); // Mảng lưu sức chứa còn lại của mỗi cạnh

    // Tính giá trị cho mảng r
    for (int u = 0; u < V; u++)
    {
        for (const canh& canh : graph[u])
            r[canh.u][canh.v] = canh.c - canh.f;
    }

    // Mảng lưu trữ đỉnh cha của mỗi đỉnh trong đường mở rộng
    vector<int> cha(V, -1);

    int maxflow = 0; // Dòng cực đại có thể đi qua đồ thị

    // Thuật toán BFS tìm đường đi từ đỉnh s đến t
    while (true)
    {
        vector<bool> visited(V, false); // Mảng đánh dấu các đỉnh đã đi qua
        fill(cha.begin(), cha.end(), -1);
        queue<int> q; // Hàng đợi lưu các đỉnh

        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            // Duyệt các đỉnh kề đỉnh u
            for (const canh& canh : graph[u])
            {
                int v = canh.v;

                if (r[u][v] > 0 && !visited[v])
                {
                    visited[v] = true;
                    cha[v] = u;
                    q.push(v);
                }
            }
        }

        // Nếu không có đường đi từ s đến t thì dừng
        if (!visited[t])
            break;

        // Tìm lưu lượng tối đa có thể tăng thêm dọc theo đường mở rộng
        int them = INT_MAX;

        for (int v = t; v != s; v = cha[v])
        {
            int u = cha[v];
            them = min(them, r[u][v]);
        }

        // Cập nhật lưu lượng và sức chứa còn lại của mỗi cạnh trên đường mở rộng
        for (int v = t; v != s; v = cha[v])
        {
            int u = cha[v];
            for (canh& canh : graph[u])
            {
                if (canh.v == v)
                {
                    canh.f += them;
                    r[u][v] -= them;
                    r[v][u] += them;
                    break;
                }
            }
        }

        maxflow += them; // Cập nhật giá trị cho lưu lượng tối đa
    }

    return maxflow;
}

int main()
{
    freopen(".inp", "r", stdin);

    int N, M;
    cin >> N >> M;

    int s, t;
    cin >> s >> t;

    vector<vector<canh>> graph(N);

    // Nhập các cạnh
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u - 1].emplace_back(u - 1, v - 1, c);
    }

    // Tìm dòng cực đại bằng thuật toán Edmonds-Karp
    int maxflow = max_flow(graph, s - 1, t - 1);
    cout << maxflow;

    return 0;
}
