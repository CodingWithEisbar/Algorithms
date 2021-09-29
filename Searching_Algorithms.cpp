/*
################################################################
Tổng hợp những thuật toán tìm kiếm (Searching Algorithms)
Data type: Interger (int)
Array type: Sorted

1. Binary Search (Tìm kiếm nhị phân)
2. Interpolation Search (Tìm kiếm nội suy)
3. Ternary Search (Tìm kiếm tam phân)
4. Meta binary Search
5. Jump Search (Tìm kiếm )
6. Exponential Search (Tìm kiếm cấp số mũ)
7. Fibonacci search
################################################################
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <time.h>
using namespace std;

//Data Generator (Các hàm khởi tạo dữ liệu)
//---------------------------------------------------------------
template <class T>
void hoanVi(T &a, T &b)
{
    T x = a;
    a = b;
    b = x;
}
// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
}
// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}
// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - 1 - i;
    }
}
// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int r1 = rand() % n;
        int r2 = rand() % n;
        hoanVi(a[r1], a[r2]);
    }
}
void GenerateData(int a[], int n, int dataType)
{
    switch (dataType)
    {
    case 0: // ngẫu nhiên
        GenerateRandomData(a, n);
        break;
    case 1: // có thứ tự
        GenerateSortedData(a, n);
        break;
    case 2: // có thứ tự ngược
        GenerateReverseData(a, n);
        break;
    case 3: // gần như có thứ tự
        GenerateNearlySortedData(a, n);
        break;
    default:
        cout << "Error: unknown data type!\n";
    }
}
//Searching Algorithms (Các thuật toán tìm kiếm)
//---------------------------------------------------------------

//1.
//Work correctly on ascending sorted array
int binarySearchRecursive(int a[], int n, int left, int right, int x)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return binarySearchRecursive(a, n, left, mid - 1, x);
        return binarySearchRecursive(a, n, mid + 1, right, x);
    }
    //We reach here when element is not present in array
    return -1;
}

int binarySearchWhile(int a[], int n, int x)
{
    int right = 0, left = n - 1;
    int mid;
    while (right <= left)
    {
        mid = (right + left) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            left = mid - 1;
        else
            right = mid + 1;
    }
    return -1;
}

//2.
int interpolationSearch(int a[], int n, int x)
{
}

//3.
int ternarySearch(int a[], int n, int x)
{
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int n, *a, left = 0, right = n - 1;
    cin >> n;
    a = new int[n];
    GenerateSortedArray(a, n);
    printArray(a, n);
    int res01 = binarySearchWhile(a, n, 77);
    int res02 = binarySearchRecursive(a, n, )
                    cout
                << "\nResult 01: " << res01;
    delete[] a;
    return 0;
}