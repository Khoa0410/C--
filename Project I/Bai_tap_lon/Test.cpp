// Nguyễn Đức Khoa - 20215599
// Đề tài: Lập trình ứng dụng thực hiện các thuật toán sắp xếp

#include <bits/stdc++.h>
#include <fcntl.h>
using namespace std;

wofstream output;

int N;
int selec, a;
int A[100000];

void print(int arr[], int l, int r)
{
    if (!a)
    {
        for (int i = l; i <= r; i++)
            wcout << arr[i] << ' ';
        wcout << '\n';
    }
    else
    {
        for (int i = l; i <= r; i++)
            output << arr[i] << ' ';
        output << '\n';
    }
}

void Selection_Sort(int a[], int n)
{
    // Thời điểm bắt đầu thuật toán
    auto start = chrono::high_resolution_clock::now();

    // Sao chép dãy a[n] vào b[n]
    int b[n];
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (b[min] > b[j])
                min = j;
        swap(b[min], b[i]);
    }

    auto end = chrono::high_resolution_clock::now(); // Thời điểm kết thúc thuật toán
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    wcout << L"Thời gian thực hiện theo Selection Sort: " << duration.count() << " microseconds\n";
}

void Insertion_Sort(int a[], int n)
{
    // Thời điểm bắt đầu thuật toán
    auto start = chrono::high_resolution_clock::now();

    // Sao chép dãy a[n] vào b[n]
    int b[n];
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    for (int i = 1; i < n; i++)
    {
        int last = b[i];
        int j = i;

        while (j > 0 && b[j - 1] > last)
        {
            b[j] = b[j - 1];
            j--;
        }
        b[j] = last;
    }

    auto end = chrono::high_resolution_clock::now(); // Thời điểm kết thúc thuật toán
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    wcout << L"Thời gian thực hiện theo Insertion Sort: " << duration.count() << " microseconds\n";
}

void Bubble_Sort(int a[], int n)
{
    // Thời điểm bắt đầu thuật toán
    auto start = chrono::high_resolution_clock::now();

    // Sao chép dãy a[n] vào b[n]
    int b[n];
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    bool swap = true;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (b[i] > b[i + 1])
            {
                int tmp = b[i];
                b[i] = b[i + 1];
                b[i + 1] = tmp;
                swap = true;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now(); // Thời điểm kết thúc thuật toán
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    wcout << L"Thời gian thực hiện theo Bubble Sort: " << duration.count() << " microseconds\n";
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

void Merge_Sort(int A[], int N)
{
    // Thời điểm bắt đầu thuật toán
    auto start = chrono::high_resolution_clock::now();

    // Sao chép dãy A[N] vào b[N]
    int b[N];
    for (int i = 0; i < N; i++)
        b[i] = A[i];

    MergeSort(b, 0, N - 1);

    auto end = chrono::high_resolution_clock::now(); // Thời điểm kết thúc thuật toán
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    wcout << L"Thời gian thực hiện theo Merge Sort: " << duration.count() << " microseconds\n";
}

/* Hàm thực hiện xếp các phần tử nhỏ hơn phần tử trụ(pivot) đứng trước phần tử trụ
 và các phần tử lớn hơn phần tử trụ đứng sau phần tử trụ
 sau đó trả về vị trí phần tử trụ(đã xếp đúng vị trí) trong Quick Sort */
int index_pivot(int A[], int L, int R, int index_pre_pivot)
{
    int pre_pivot = A[index_pre_pivot];
    swap(A[R], A[index_pre_pivot]);
    int index = L;

    // Xếp các phần tử nhỏ hơn phần tử trụ lên đầu mảng
    for (int i = L; i < R; i++)
    {
        if (A[i] < pre_pivot)
        {
            swap(A[i], A[index]);
            index++;
        }
    }

    swap(A[R], A[index]); // Đưa phần tử trụ về đúng vị trí
    return index;
}

// Hàm đệ quy thực hiện sắp xếp QuickSort
void QuickSort(int A[], int L, int R)
{
    if (L < R)
    {
        int M = L + (R - L) / 2;
        M = index_pivot(A, L, R, M);
        QuickSort(A, L, M - 1);
        QuickSort(A, M + 1, R);
    }
}

void Quick_Sort(int A[], int N)
{
    // Thời điểm bắt đầu thuật toán
    auto start = chrono::high_resolution_clock::now();

    // Sao chép dãy A[N] vào b[N]
    int b[N + 1];
    for (int i = 0; i < N; i++)
        b[i] = A[i];

    QuickSort(b, 0, N - 1);

    auto end = chrono::high_resolution_clock::now(); // Thời điểm kết thúc thuật toán
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    wcout << L"Thời gian thực hiện theo Quick Sort: " << duration.count() << " microseconds\n";
}

// Hàm vun lại đống cho phần tử thứ i
void heapify(int A[], int i, int N)
{
    int L = 2 * i;
    int R = 2 * i + 1;
    int max = i;
    if (L <= N && A[L] > A[i])
        max = L;
    if (R <= N && A[R] > A[max])
        max = R;
    if (max != i)
    {
        swap(A[i], A[max]);
        heapify(A, max, N);
    }
}

// Xây dựng max heap
void buildHeap(int A[], int N)
{
    for (int i = N / 2; i >= 1; i--)
        heapify(A, i, N);
}

void Heap_Sort(int A[], int N)
{
    // Thời điểm bắt đầu thuật toán
    auto start = chrono::high_resolution_clock::now();

    // Sao chép dãy A[N] vào b[N + 1]
    int b[N + 1];
    for (int i = 0; i < N; i++)
        b[i + 1] = A[i];

    buildHeap(b, N);
    for (int i = N; i > 1; i--)
    {
        swap(b[1], b[i]);
        heapify(b, 1, i - 1);
    }

    auto end = chrono::high_resolution_clock::now(); // Thời điểm kết thúc thuật toán
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    wcout << L"Thời gian thực hiện theo Heap Sort: " << duration.count() << " microseconds\n";
}

int main()
{
    // Thiết lập chế độ unicode cho luồng nhập và xuất
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
    ifstream file(".inp"); // Đọc dữ liệu đầu vào từ file .inp
    output.open(".out");   // Ghi dữ liệu kết quả ra file .out
    output.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    int count = 0; // Số lượng dãy số được sắp xếp
    wcout << L"0.Nhập dữ liệu bằng bàn phím" << '\n';
    wcout << L"1.Nhập dữ liệu bằng file" << '\n';
    wcout << "----------------" << '\n';
    wcout << L"Mời nhập lựa chọn của bạn: ";
    wcin >> a;
    
    if (!a)
    {
        wcout << "1.Selection Sort." << '\n';
        wcout << "2.Insertion Sort." << '\n';
        wcout << "3.Bubble Sort." << '\n';
        wcout << "4.Merge Sort." << '\n';
        wcout << "5.Quick Sort." << '\n';
        wcout << "6.Heap Sort." << '\n';
        wcout << L"7.Nhập dữ liệu cho mảng cần sắp xếp" << '\n';
        wcout << L"0.Thoát" << '\n';
        wcout << "----------------" << '\n';
    }

    while (true)
    {
        if (!a)
        {
            wcout << L"Mời nhập lựa chọn của bạn: ";
            wcin >> selec;
        }
        else
            file >> selec;

        switch (selec)
        {
        case 0:
            if(!a)  wcout << L"Bạn đã lựa chọn thoát chương trình";
            this_thread::sleep_for(5s);
            return 0;
            break;

        case 1:
            Selection_Sort(A, N);
            break;

        case 2:
            Insertion_Sort(A, N);
            break;

        case 3:
            Bubble_Sort(A, N);
            break;

        case 4:
            Merge_Sort(A, N);
            break;

        case 5:
            Quick_Sort(A, N);
            break;

        case 6:
            Heap_Sort(A, N);
            break;

        case 7:
            count ++;
            if (!a)
            {
                wcout << L"Nhập số phần tử cho mảng: ";
                wcin >> N;
                wcout << L"Nhập các giá trị cho mảng: ";
                for (int i = 0; i < N; i++)
                    wcin >> A[i];
            }
            else
            {
                file >> N;
                for (int i = 0; i < N; i++)
                    file >> A[i];
            }

            int *b = new int[N + 1];
            for (int i = 0; i < N; i++)
                b[i + 1] = A[i];

            buildHeap(b, N);
            for (int i = N; i > 1; i--)
            {
                swap(b[1], b[i]);
                heapify(b, 1, i - 1);
            }

            if (!a)     wcout << L"Dãy đã được sắp xếp: ";
            print(b, 1, N);
            delete[] b;
            if(a)       wcout << L"Thời gian thực hiện dãy thứ " << count << ": " << "\n";
            break;
        }
    }

    return 0;
}