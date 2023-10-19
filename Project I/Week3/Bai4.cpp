/*There are two jugs, a-litres jug and b-litres jug (a, b are positive integers).
There is a pump with unlimited water. Given a positive integer c, how to get exactly c litres.*/

#include<bits/stdc++.h>
using namespace std;

// Cấu trúc State lưu trạng thái của 2 bể
struct State
{
    int x, y;
    State *p;
};

// Mảng 2 chiều đánh dấu các trạng thái đã được xét
bool visited[10000][10000];

queue<State *> Q; // Hàng đợi lưu các trạng thái
list<State *> L; // Danh sách L lưu các con trỏ trỏ đến các vùng nhớ được cấp phát động
State *target; // Lưu trạng thái cuối cùng của 2 bể
int a, b, c;

// Khởi tạo giá trị mảng visited thành false
void khoi_tao_mang()
{
    for(int i = 0; i < 10000; i++)
        for(int j = 0; j < 10000; j++)
            visited[i][j] = false;
}

bool ktra_dk_ket_thuc(State* S)
{
    return S->x == c || S->y == c || (S->x + S->y) == c;
}

void danh_dau(State* S)
{
    visited[S->x][S->y] = true;
}

void freeMemory()
{
    list<State *>::iterator it;
    for (it = L.begin(); it != L.end(); it++)
    {
        delete *it;
    }
}

// Đổ nước ở cốc 1 ra ngoài
bool do_coc1_di(State* S)
{
    if(visited[0][S->y])    return false;
    State* tmp = new State;
    tmp->x = 0;
    tmp->y = S->y;
    tmp->p = S;
    Q.push(tmp);
    danh_dau(tmp);
    L.push_back(tmp);
    if(ktra_dk_ket_thuc(tmp))
    {
        target = tmp;
        return true;
    }
    return false;
}

// Đổ nước ở cốc 2 ra ngoài
bool do_coc2_di(State* S)
{
    if(visited[S->x][0])    return false;
    State* tmp = new State;
    tmp->x = S->x;
    tmp->y = 0;
    tmp->p = S;
    Q.push(tmp);
    danh_dau(tmp);
    L.push_back(tmp);
    if(ktra_dk_ket_thuc(tmp))
    {
        target = tmp;
        return true;
    }
    return false;
}

// Đổ nước từ cốc 1 vào đầy cốc 2
bool do_1_vao_day_2(State* S)
{
    if(S->x + S->y < b) return false;
    if(visited[S->x + S->y - b][b])    return false;
    State* tmp = new State;
    tmp->x = S->x + S->y - b;
    tmp->y = b;
    tmp->p = S;
    Q.push(tmp);
    danh_dau(tmp);
    L.push_back(tmp);
    if(ktra_dk_ket_thuc(tmp))
    {
        target = tmp;
        return true;
    }
    return false;
}

// Đổ nước từ cốc 2 vào đầy cốc 1
bool do_2_vao_day_1(State* S)
{
    if(S->x + S->y < a) return false;
    if(visited[a][S->x + S->y - a])    return false;
    State* tmp = new State;
    tmp->x = a;
    tmp->y = S->x + S->y - a;
    tmp->p = S;
    Q.push(tmp);
    danh_dau(tmp);
    L.push_back(tmp);
    if(ktra_dk_ket_thuc(tmp))
    {
        target = tmp;
        return true;
    }
    return false;
}

// Đổ hết nước từ cốc 1 sang cốc 2
bool do_1_vao_2(State* S)
{
    if(S->x + S->y > b) return false;
    if(visited[0][S->x + S->y])    return false;
    State* tmp = new State;
    tmp->x = 0;
    tmp->y = S->x + S->y;
    tmp->p = S;
    Q.push(tmp);
    danh_dau(tmp);
    L.push_back(tmp);
    if(ktra_dk_ket_thuc(tmp))
    {
        target = tmp;
        return true;
    }
    return false;
}

// Đổ hết nước từ cốc 2 sang cốc 1
bool do_2_vao_1(State* S)
{
    if(S->x + S->y > a) return false;
    if(visited[S->x + S->y][0])    return false;
    State* tmp = new State;
    tmp->x = S->x + S->y;
    tmp->y = 0;
    tmp->p = S;
    Q.push(tmp);
    danh_dau(tmp);
    L.push_back(tmp);
    if(ktra_dk_ket_thuc(tmp))
    {
        target = tmp;
        return true;
    }
    return false;
}

// Đổ đầy nước từ bể vào cốc 1
bool do_vao_1(State* S)
{
    if(visited[a][S->y])    return false;
    State* tmp = new State;
    tmp->x = a;
    tmp->y = S->y;
    tmp->p = S;
    Q.push(tmp);
    danh_dau(tmp);
    L.push_back(tmp);
    if(ktra_dk_ket_thuc(tmp))
    {
        target = tmp;
        return true;
    }
    return false;
}

// Đổ đầy nước từ bể vào cốc 2
bool do_vao_2(State* S)
{
    if(visited[S->x][b])    return false;
    State* tmp = new State;
    tmp->x = S->x;
    tmp->y = b;
    tmp->p = S;
    Q.push(tmp);
    danh_dau(tmp);
    L.push_back(tmp);
    if(ktra_dk_ket_thuc(tmp))
    {
        target = tmp;
        return true;
    }
    return false;
}

// In kết quả
void print(State* target)
{
    if(target == NULL)
    {
        cout << "-1";
        return;
    }

    State* currentS = target;
    stack<State*> actions; // Ngăn xếp lưu chuỗi các trạng thái thực hiện đổ nước để đạt kết quả

    while(currentS != NULL)
    {
        actions.push(currentS);
        currentS = currentS->p;
    }
    
    cout << actions.size() - 1;
    return;
}

void Solve()
{
    khoi_tao_mang();
    // Sinh ra trạng thái ban đầu (0,0) và đưa vào Q
    State* S = new State();
    S->x = 0; S->y = 0; S->p = NULL;
    Q.push(S);
    danh_dau(S);

    while(!Q.empty())
    {
        State* S = Q.front();
        Q.pop();
        if(do_coc1_di(S))   break;
        if(do_coc2_di(S))   break;
        if(do_1_vao_day_2(S))   break;
        if(do_2_vao_day_1(S))   break;
        if(do_1_vao_2(S))   break;
        if(do_2_vao_1(S))   break;
        if(do_vao_1(S))     break;
        if(do_vao_2(S))     break;
    }
}

int main()
{
    cin >> a >> b >> c;
    target = NULL;
    Solve();
    print(target);
    freeMemory();
    return 0;
}