/*Given a directed graph G = (V,E) in which V = {1,2,...,n) is the set of nodes.
Each arc (u,v) has a non-negative weight w(u,v).
Given two nodes s and t of G. Find the shortest path from s to t on G.*/

#include<bits/stdc++.h>
using namespace std;

#define N 100005

int n, m;
int sum;
int G[N][N] = {};
vector<bool>  visited;
vector<int> SUM;

void input()
{
    cin >> n >> m;
    sum = 0;
    visited.resize(n + 1, false);

    for(int i = 0; i < m; i++)
    {
        int tmp1, tmp2, w;
        cin >> tmp1 >> tmp2 >> w;
        G[tmp1][tmp2] = w;
    }
}

// Tìm tổng trọng số đường đi từ đỉnh s đến đỉnh t
void find_way(int s, int t)
{
    if(s == t)  return;

    if(!visited[s])
    {
        visited[s] = true;
        for(int i = 1; i <= n; i++)
        {
            if(G[s][i])
            {
                sum += G[s][i];
                find_way(i, t);
                SUM.push_back(sum);

                // Thực hiện quay lui
                sum -= G[s][i];
            }
        }
    }
}

int main()
{
    freopen(".inp", "r", stdin);

    input();

    int s, t;
    cin >> s >> t;
    find_way(s, t);
    sort(SUM.begin(), SUM.end());
    cout << SUM.front();

    return 0;
}