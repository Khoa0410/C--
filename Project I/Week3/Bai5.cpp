/*Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
· PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
· InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
· PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int id;
    Node* LeftMostChild;
    Node* RightSibling;
};

Node* goc;

// Tạo nút mới có id = u
Node* TaoNut(int u)
{
    Node* p = new Node;
    p->id = u;
    p->RightSibling = NULL;
    p->LeftMostChild = NULL;
    return p;
}

// Tìm nút có id = u
Node* TimNut(Node* r, int u)
{
    if(r == NULL)   return NULL;
    if(r->id == u)  return r;
    Node* p = r->LeftMostChild;
    while(p != NULL)
    {
        Node* h = TimNut(p, u);
        if(h != NULL)   return h;
        p = p->RightSibling;
    }
    return NULL;
}

// Tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v
void ThemNut(int u, int v)
{
    Node* tmp1 = TimNut(goc, u);
    if (tmp1 != NULL) return; // Nếu nút có id = u đã có thì không tạo nút mới
    Node* tmp2 = TimNut(goc, v);
    if (tmp2 == NULL) return; // Nếu nút có id = v chưa có thì không tạo nút mới

    Node* p = tmp2->LeftMostChild;
    if (p == NULL)
    {
        // Nếu nút v không có nút con, thêm nút mới là con trái của nút v
        tmp2->LeftMostChild = TaoNut(u);
    }
    else
    {
        while (p->RightSibling != NULL)
            p = p->RightSibling;
        p->RightSibling = TaoNut(u); // Thêm nút u vào cuối danh sách nút con của nút v
    }
}

// Duyệt trước
void PreOrder(Node* r)
{
    if(r == NULL)   return;
    cout << r->id << ' ';
    Node*p = r->LeftMostChild;
    while(p != NULL)
    {
        PreOrder(p);
        p = p->RightSibling;
    }
    return;
}

// Duyệt giữa
void InOrder(Node* r)
{
    if(r == NULL)   return;
    Node* p = r->LeftMostChild;
    InOrder(p);
    cout << r->id << ' ';
    if(p != NULL)
    {
        p = p->RightSibling;
        while(p != NULL)
        {
            InOrder(p);
            p = p->RightSibling;
        }
    }
    return;
}

// Duyệt sau
void PostOrder(Node* r)
{
    if(r == NULL)   return;
    Node* p = r->LeftMostChild;
    while(p != NULL)
    {
        PostOrder(p);
        p = p->RightSibling;
    }
    cout << r->id << ' ';
    return;
}

int main()
{
    freopen(".inp", "r", stdin);
    while(true)
    {
        string s;
        cin >> s;
        if(s == "*")    break;

        // Tạo nút gốc
        if(s == "MakeRoot")
        {
            int u;
            cin >> u;
            goc = TaoNut(u);
        }

        // Chèn nút mới
        if(s == "Insert")
        {
            int u, v;
            cin >> u >> v;
            ThemNut(u, v);
        }

        // Duyệt trước
        if(s == "PreOrder")
        {
            PreOrder(goc);
            cout << endl;
        }

        // Duyệt giữa
        if(s == "InOrder")
        {
            InOrder(goc);
            cout << endl;
        }

        // Duyệt sau
        if(s == "PostOrder")
        {
            PostOrder(goc);
            cout << endl;
        }
    }
    
    return 0;
}