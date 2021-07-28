#include "20127404_Header.h"


void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}


int main() {
	int* a, n,choice;
	double time_taken;
	cout << "Enter n: ";
	cin >> n;
	a = new int[n];\
	
	cout << "\nChoose your array type: ";
	cout << "\n\t1 - Ascending array";
	cout << "\n\t2 - Descending array"<<endl;
	cin >> choice;
	if (choice == 1) {
		GenerateSortedData(a, n);
	/*	cout << "Your array: "; printArray(a, n);*/
		srand((unsigned)time(NULL));
		int x = rand() % n;
		cout << "\nx is: " << x << endl;
		//Time measure
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);
		int res = exponentialSearchAscending(a, n, x);
		auto end = chrono::high_resolution_clock::now();
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-6;

		cout << "Time taken: " << time_taken << endl;
		if (res == -1) cout << "\n\tNot found";
		else cout << res << endl;
	}
	else if (choice == 2) {
		GenerateReverseData(a, n);
		//cout << "Your array: "; printArray(a, n);
		srand((unsigned)time(NULL));
		int x = rand() % n;
		cout << "\nx is: " << x << endl;
		//Time measure
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);
		int res = exponentialSearchDescending(a, n, x);
		auto end = chrono::high_resolution_clock::now();
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-6;

		cout << "Time taken: " << time_taken << endl;
		if (res == -1) cout << "\n\tNot found";
		else cout << res << endl;
	}
	else cout << "\nInvalid choice";
	
	delete[]a;
	return 0;
}