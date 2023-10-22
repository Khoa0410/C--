/*Viết chương trình thực hiện công việc sau:
Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy a1, a2, …, an,
sau đó thực hiện các thao tác trên danh sách bao gồm:
thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước,
vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *next;
};

Node *head;

// Tạo nút mới có key = k
Node *MakeNode(int k)
{
    Node *r = new Node;
    r->key = k;
    r->next = NULL;
    return r;
}

// Kiểm tra khóa k có trong danh sách chưa
bool FindNode(Node *h, int k)
{
    if (h == NULL)
        return false;
    while (h != NULL)
    {
        if (h->key == k)
            return true;
        h = h->next;
    }
    return false;
}

// Thêm phần tử mới có key = k vào cuối danh sách
void AddLast(Node *&h, int k)
{
    if (h == NULL)
        h = MakeNode(k);
    else
    {
        Node *p = h;
        if (p->key == k)
            return; // nếu đã có khóa k trong danh sách thì ko thêm
        while (p->next != NULL)
        {
            p = p->next;
            if (p->key == k)
                return; // nếu đã có khóa k trong danh sách thì ko thêm
        }
        p->next = MakeNode(k);
    }
    return;
}

// Thêm phần tử mới có key = k vào đầu danh sách
Node *AddFirst(Node *h, int k)
{
    if (FindNode(h, k))
        return h;
    else
    {
        Node *q = MakeNode(k);
        q->next = h;
        return q;
    }
}

// Loại bỏ phần tử có key bằng k khỏi danh sách
void ReMove(Node *&h, int k)
{
    if (!FindNode(h, k))
        return;
    else
    {
        if (h->key == k)
            h = h->next;
        else
        {
            Node *p = h;
            Node *q = p;
            while (p->key != k)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
        }
    }
    return;
}

// Thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách
void AddAffter(Node *h, int u, int v)
{
    if (FindNode(h, v) == true && FindNode(h, u) == false)
    {
        Node *p = h;
        while (p->key != v)
            p = p->next;
        Node *q = MakeNode(u);
        q->next = p->next;
        p->next = q;
    }
    return;
}

// Thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách
void AddBefore(Node *h, int u, int v)
{
    if (FindNode(h, v) == true && FindNode(h, u) == false)
    {
        Node *p = h;
        while ((p->next)->key != v)
            p = p->next;
        Node *q = MakeNode(u);
        q->next = p->next;
        p->next = q;
    }
    return;
}

// Đảo ngược thứ tự các phần tử của danh sách
void Reverse(Node *&h)
{
    Node *previous = nullptr;
    Node *current = h;

    while (current != nullptr)
    {
        Node *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    h = previous;
}

int main()
{
    //freopen(".inp", "r", stdin);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        AddLast(head, a[i]);
    }

    while (true)
    {
        string s;
        cin >> s;
        if (s == "#")
            break;

        // Thêm phần tử vào cuối danh sách
        if (s == "addlast")
        {
            int k;
            cin >> k;
            AddLast(head, k);
        }

        // Thêm phần tử vào đầu danh sách
        if (s == "addfirst")
        {
            int k;
            cin >> k;
            head = AddFirst(head, k);
        }

        // Loại bỏ phần tử có key bằng k khỏi danh sách
        if (s == "remove")
        {
            int k;
            cin >> k;
            ReMove(head, k);
        }

        // Thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách
        if (s == "addafter")
        {
            int u, v;
            cin >> u >> v;
            AddAffter(head, u, v);
        }

        // Thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách
        if (s == "addbefore")
        {
            int u, v;
            cin >> u >> v;
            AddBefore(head, u, v);
        }

        // Đảo ngược thứ tự các phần tử của danh sách
        if (s == "reverse")
            Reverse(head);
    }

    // In ra dãy khóa trong danh sách
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->key << ' ';
        tmp = tmp->next;
    }
    return 0;
}