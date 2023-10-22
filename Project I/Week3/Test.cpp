/*Given a BST initialized by NULL. Perform a sequence of operations on a BST including:
insert k: insert a key k into the BST (do not insert if the key k exists)*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node* trai;
    Node* phai;
};

Node* goc;

// Tạo nút mới có key = u
Node* MakeNode(int u)
{
    Node* p = new Node;
    p->key = u;
    p->phai = NULL;
    p->trai = NULL;
    return p;
}

// Chèn 1 nút có khóa = k vào BST
void Insert(Node*& r, int k)
{
    if(r == NULL)   r = MakeNode(k);
    else
    {
        if(r->key == k)     return; // Nếu có nút có khóa = k thì không chèn
        if(r->key > k)      Insert(r->trai, k);
        if(r->key < k)      Insert(r->phai, k);
    }
    return;
}

// Duyệt cây theo thứ tự trước
void PreOrder(Node* r)
{
    if(r == NULL)   return;
    cout << r->key << ' ';
    Node* p = r->trai;
    PreOrder(p);
    Node* q = r->phai;
    PreOrder(q);
    return;
}

int main()
{
    //freopen(".inp", "r", stdin);

    goc = NULL;
    while(true)
    {
        string s;
        cin >> s;
        if(s == "#")    break;
        if(s == "insert")
        {
            int k; cin >> k;
            Insert(goc, k);
        }
    }
    PreOrder(goc);
    return 0;
}