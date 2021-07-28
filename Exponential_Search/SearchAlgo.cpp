#include "20127404_Header.h"

//Ascending
int BinarySearchAscending(int a[], int left, int right, int x) 
{	

	if (right >= left) {
		int middle = left + (right - left) / 2;
		if (a[middle] == x) {
			return middle;
		}
		if (a[middle] > x) return BinarySearchAscending(a, left, middle - 1, x);
		return BinarySearchAscending(a, middle + 1, right, x);
		

	}
	return -1;
}
 

int exponentialSearchAscending(int a[], int n, int x)
{
	
	if (a[0] == x) {
		return 0;
	}
	
	int i = 1;
	while (i < n && a[i] <= x) i = i * 2;
	return BinarySearchAscending(a, i/2, min(i, n - 1), x);
	
}

//Descending
int BinarySearchDescending(int a[], int left, int right, int x)
{

	if (right >= left) {
		int middle = left + (right - left) / 2;
		if (a[middle] == x) {
			return middle;
		}
		if (a[middle] < x) return BinarySearchDescending(a, left, middle - 1, x);
		return BinarySearchDescending(a, middle + 1, right, x);
	}
	return -1;
}


int exponentialSearchDescending(int a[], int n, int x)
{
	
	if (a[0] == x) {
		return 0;
	}
	int i = 1;
	while (i < n && a[i] >= x) i = i * 2;
	return BinarySearchDescending(a, i / 2, min(i, n - 1), x);
}
