/*
################################################################
Tổng hợp những thuật toán sắp xếp (Sorting Algorithms)
-Basic-
1. Bubble sort
2. Shake sort
3. Insertion sort
4. Selection sort
5. Counting sort
6. Merge sort
7. Shell sort
8. Heap sort
9. Quick sort
10. Radix sort
11. Flash sort

-Advanced-
1. Bucket sort
2. Intro sort
################################################################ 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <time.h>
#include <cstring>
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

//Basic sorting algorithms (Các thuật toán sắp xếp cơ bản)
//---------------------------------------------------------------
//Áp dụng cho kiểu dữ liệu số nguyên (integer)
//1.
void bubbleSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[j] < a[j - 1])
				hoanVi(a[j], a[j - 1]);
		}
	}
}

//2.
void shakeSort(int a[], int n)
{
	int left, right, j, k;
	left = 1;
	right = n - 1;
	do
	{
		for (j = right; j >= left; j--)
			if (a[j - 1] > a[j])
			{
				hoanVi(a[j], a[j - 1]);
				k = j;
			}
		left = k + 1;
		for (j = left; j <= right; j++)
			if (a[j - 1] > a[j])
			{
				hoanVi(a[j], a[j - 1]);
				k = j;
			}
		right = k - 1;
	} while (left <= right);
}

//3.
void insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int v = a[i];
		int j = i - 1;
		for (; j >= 0 && a[j] > v; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = v;
	}
}

void insertionSort(vector<double>& bucket) //Dành cho thuật toán bucket sort
{
	int n = bucket.size();
	for (int i = 0; i<n; i++)
	{
		float key = bucket[i];
		int j = i-1;
		while (j>= 0 && bucket[j] > key)
		{
			bucket[j+1] = bucket[j];
			j--;
		}
		bucket[j+1] = key;
	}
}

//4.
void selectionSort(int a[], int n)
{
	int minIndex;
	for (int i = 0; i < n - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[minIndex])
				minIndex = j;
		}
		hoanVi(a[i], a[minIndex]);
	}
}

//5.
void countingSort(int a[], int n)
{
	int *b = new int[n];
	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
			min = a[i];
	}
	int cnt = max - min + 1;
	int *cnt_arr = new int[cnt];
	memset(cnt_arr, 0, cnt * sizeof(int)); //Set all element's value of cnt_arr is 0
	for (int i = 0; i < n; i++)
		cnt_arr[a[i] - min]++;
	for (int i = 1; i < cnt; i++)
		cnt_arr[i] += cnt_arr[i - 1];
	for (int i = 0; i < n; i++)
	{
		b[cnt_arr[a[i] - min] - 1] = a[i];
		cnt_arr[a[i] - min]--;
	}
	memcpy(a, b, n * sizeof(int)); //Copy ouput array to given array
	delete[] b;
	delete[] cnt_arr;
}

//6.
void merge(int a[], int left, int middle, int right)
{
	//Initial the sub array size
	int subArrayOne = middle - left + 1;
	int subArrayTwo = right - middle;

	//Create temp subarray
	vector<int> Left(subArrayOne);
	vector<int> Right(subArrayTwo);

	//Copy data to 2 subarray left, right
	


}

void mergeSort(int a[], int n)
{
	//the middle value is determine in this function
	
}

//7.
void shellSort(int a[], int n)
{
	int interval, i, j, temp;
	for (interval = n / 2; interval > 0; interval /= 2)
	{
		for (i = interval; i < n; i++)
		{
			temp = a[i];
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
			{
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
}

//8.
void heapify(int a[], int n, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int root = i;
	if (left < n && a[root] < a[left])
		root = left;
	if (right < n && a[root] < a[right])
		root = right;
	if (root != i)
	{
		hoanVi(a[root], a[i]);
		heapify(a, n, root);
	}
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		hoanVi(a[0], a[i]);
		heapify(a, i, 0);
	}
}

//9.
int partition(int a[], int left, int right)
{
	return 0;
}

void quickSort(int a[], int n)
{
}

//10.
void countSort(int a[], int n, int exp)
{
	int *result = new int[n];
	memset(result, 0, n * sizeof(int));
	int i, bucket[10] = {0};
	for (i = 0; i < n; i++)
		bucket[(a[i] / exp) % 10]++;
	for (int i = 1; i < 10; i++)
		bucket[i] += bucket[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		result[bucket[(a[i] / exp) % 10] - 1] = a[i];
		bucket[(a[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		a[i] = result[i];
	delete[] result;
}

void radixSort(int a[], int n)
{
	int maxInArr = a[0];
	for (int i = 0; i < n; i++)
		if (maxInArr < a[i])
			maxInArr = a[i];
	for (int exp = 1; maxInArr / exp > 0; exp *= 10)
		countSort(a, n, exp);
}

//11.
void flashSort(int a[], int n)
{
	int max = 0, min = a[0];
	int m = floor(0.45 * n);
	vector<int> l;
	l.resize(m);
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > a[max])
		{
			max = i;
		}
	}
	if (min == a[max])
	{
		return;
	}
	double c1 = (double)(m - 1) / (a[max] - min);

	for (int k = 0; k < m; k++)
	{
		l[k] = 0;
	}
	for (int j = 0; j < n; j++)
	{
		int k = int(c1 * (a[j] - min));
		++l[k];
	}
	for (int p = 1; p < m; p++)
	{
		l[p] = l[p] + l[p - 1];
	}

	swap(a[0], a[max]);

	// permutation - hoán vị
	int move = 0, t = 0, flash;
	int j = 0;
	int k = m - 1;

	while (move < (n - 1))
	{
		while (j > (l[k] - 1))
		{
			++j;
			k = int(c1 * (a[j] - min));
		}
		flash = a[j];
		if (k < 0)
			break;
		while (j != l[k])
		{
			k = int(c1 * (flash - min));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++move;
		}
	}
	//insertion
	for (int i = 1; i < n; i++)
	{
		int v = a[i];
		int j = i - 1;
		for (; j >= 0 && a[j] > v; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = v;
	}
}

//Advanced sorting algorithms (Các thuật toán sắp xếp nâng cao)
//---------------------------------------------------------------

//1.
//Áp dụng cho kiểu dữ liệu float, double 
void bucketSort(int a[], int n)
{
	//a. Tạo một bucket rỗng để chứa các phần tử trong mảng
	vector<double> bucket[n];
	//b. Chuyển các phần tử trong mảng vào các ô bucket tương ứng 
	for (int i = 0; i<n; i++)
	{
		int bucket_index = n*a[i];
		bucket[bucket_index].push_back(a[i]);
	}

	//c. Sắp xếp lại các phần tử trong bucket một các độc lập (sử dụng kiểu insertion sort)
	for (int i = 0; i<n; i++)
	{
		insertionSort(bucket[i])
	}

	//d. Chuyển các phần tử vào lại trong mảng 
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < bucket[i].size(); j++)
		{
			a[index++] = bucket[i][j];
		}
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int main()
{
	int *a, n;
	cin >> n;
	a = new int[n];
	GenerateRandomData(a, n);
	cout << "\nYour array: ";
	printArray(a, n);
	radixSort(a, n);
	cout << "\nAfter sort: ";
	printArray(a, n);
	delete[] a;
	return 0;
}