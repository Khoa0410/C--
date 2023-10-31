/*Given a undirected connected graph G=(V,E) where V={1,…,N}.
Each edge (u,v)∈E(u,v)∈E has weight w(u,v)w(u,v).
Compute minimum spanning tree of G.*/

#include<bits/stdc++.h>
using namespace std;

#define N 100005

int n, m;
int sum; // Tổng trọng số của cây khung nhỏ nhất
struct canh
{
    int u, v; // 2 đỉnh của cạnh
    int w; // trọng số của cạnh
};

vector<canh> edge; // Mảng lưu các cạnh của đồ thị

// 2 mảng sử dụng trong cấu trúc Disjoint Set
int cha[N]; // cha[i] : nút cha của nút i, nếu i là gốc thì cha[i] = i;
int do_sau[N]; // do_sau[i] : độ sâu của nút i

// Hàm so sánh
bool ss(const canh& a, const canh& b)
{
    return a.w < b.w;
}

// Tìm cây chứa đỉnh u
int find(int u)
{
    if(cha[u] != u)     cha[u] = find(cha[u]);
    return cha[u];
}

// Ghép 2 cây chứa 2 đỉnh u và v
bool ghep(int u, int v)
{
    // Tìm 2 cây chứa 2 đỉnh u, v
    u = find(u);
    v = find(v);

    if(u == v)  return false;
    if(do_sau[u] == do_sau[v])  do_sau[u] ++;
    if(do_sau[u] < do_sau[v])   cha[u] = v;
    else                        cha[v] = u;

    return true;
}

void input()
{
    cin >> n >> m;
    edge.resize(m);
    sum = 0;
    
    // Nhập các cạnh
    for(int i = 0; i < m; ++i)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;

    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(edge.begin(), edge.end(), ss);

    // Khởi tạo cấu trúc Disjoint Set cho các đỉnh
    for(int i = 1; i <= n; i++)
    {
        cha[i] = i;
        do_sau[i] = 0;
    }
}

int main()
{
    //freopen(".inp", "r", stdin);

    input();

    for(int i = 0; i < m; ++i)
    {
        if(ghep(edge[i].u, edge[i].v))
            sum += edge[i].w;
    }

    cout << sum;

    return 0;
}