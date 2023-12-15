#include<bits/stdc++.h>
using namespace std;

void print(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

// Hàm gộp 2 mảng a[L...M] và a[M+1...R] đã sắp xếp theo MergeSort
void Merge(int a[], int L, int M, int R)
{
    int tmpa[R - L + 1]; // Mảng tạm thời để gộp 2 mảng
    int i = L, j = M + 1;
    for (int k = 0; k <= R - L; k++)
    {
        if (i > M)
        {
            tmpa[k] = a[j];
            j++;
        }
        else if (j > R)
        {
            tmpa[k] = a[i];
            i++;
        }
        else
        {
            if (a[i] < a[j])
            {
                tmpa[k] = a[i];
                i++;
            }
            else
            {
                tmpa[k] = a[j];
                j++;
            }
        }
    }

    // Cập nhật giá trị cho mảng a[]
    for (int k = 0; k <= R - L; k++)
        a[L + k] = tmpa[k];
}

// Hàm đệ quy thực hiện sắp xếp MergeSort
void MergeSort(int a[], int L, int R)
{
    if (L < R)
    {
        int M = L + (R - L) / 2;
        MergeSort(a, L, M);
        MergeSort(a, M + 1, R);
        Merge(a, L, M, R);
    }
}


int main () {
    //freopen(".inp", "r", stdin);
    ifstream ifs(".inp");
    int x;
    ifs >> x;
    int N = x;
    int A[N];
    int count = 0;
    while(ifs >> x)
    {
        A[count] = x;
        count ++;
    }
    int b[N];
    for (int i = 0; i < N; i++)
        b[i] = A[i];
    print(b, 0, N - 1);
    MergeSort(b, 0, N - 1);
    print(b, 0, N - 1);
    
    return 0;
}
