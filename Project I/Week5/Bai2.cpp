/*Given a undirected graph =(V,E) in which V = {1,2,..,n} is the set of nodes.
Write a program that visit nodes of G by a DFS (consider a lexicorgraphic order of nodes).*/

#include<bits/stdc++.h>
using namespace std;

#define N 1000

int n, m;
int A[N][N]; // A[u][] là các đỉnh kề đỉnh u
int sA[N]; // số phần tử của mảng A[u][] (số đỉnh liền kề đỉnh u)
bool visited[N]; // Mảng đánh dấu các đỉnh đã được duyệt

// Nhập input và tính giá trị cho A[][] và sA[]
void input()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        sA[i] = 0;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        A[u][sA[u]] = v;
        A[v][sA[v]] = u;
        sA[u] ++; sA[v] ++;
    }
}

// Thực hiện duyệt theo chiều sâu với đỉnh u
void dfs(int u)
{
    if(!visited[u])
    {
      cout << u <<' ';
      visited[u] = true;
      for(int i = 0; i < sA[u]; i++)
        dfs(A[u][i]);
    }    
}

int main()
{
    freopen(".inp", "r", stdin);

    input();
    
    // Khởi tạo giá trị false cho mảng visited[]
    for(int i = 1; i <= n; i++)
      visited[i] = false;

    dfs(1);

    return 0;
}