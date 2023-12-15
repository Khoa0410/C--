/*Given a directed graph G = (V,E) in which V = {1,2,...,n) is the set of nodes.
Each arc (u,v) has a non-negative weight w(u,v).
Given two nodes s and t of G. Find the shortest path from s to t on G.*/

#include<bits/stdc++.h>
using namespace std;
#define max 100005

struct canh
{
    int v; // Đỉnh kết thúc của cạnh
    int w; // Trọng số của cạnh
};

int n, m, s, t;
vector<bool> visited; // Đánh dấu các đỉnh đã được duyệt
vector<int> d; // d[i] : đường đi ngắn nhất từ đỉnh s tới đỉnh i
vector< vector<canh> > G; // Lưu các cạnh của đồ thị

void input()
{
    cin >> n >> m;

    visited.resize(n + 1, false);
    d.resize(n + 1, INT_MAX);
    G.resize(n + 1);

    for(int i = 0; i < m; ++i)
    {
        int u;
        canh canh_u;
        cin >> u >> canh_u.v >> canh_u.w;
        G[u].push_back(canh_u);
    }

    cin >> s >> t;
    d[s] = 0;
}

void Dijkstra()
{
    // Sử dụng hàng đợi ưu tiên lưu các đỉnh được duyệt
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        // Tính lại khoảng cách cho các đỉnh kề của đỉnh u
        for (auto e : G[u])
        {
            int v = e.v;
            int w = e.w;

            if (!visited[v] && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push(make_pair(d[v], v));
            }
        }
    }
}

int main()
{
    //freopen(".inp", "r", stdin);

    input();
    Dijkstra();
    cout << d[t];

    return 0;
}