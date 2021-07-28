#pragma once
#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;

//Data Generator
template <class T>
void HoanVi(T& a, T& b);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);

//Search Algorithm

int BinarySearchAscending(int a[], int left, int right, int x);
int exponentialSearchAscending(int a[], int n, int x);
int BinarySearchDescending(int a[], int left, int right, int x);
int exponentialSearchDescending(int a[], int n, int x);

//Main
void printArray(int a[], int n);