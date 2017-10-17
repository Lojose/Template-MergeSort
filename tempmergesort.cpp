#include <iostream>
#include <cassert>
#include <cstdlib> 

using namespace std;

template <class T>  
void merge(T a[], T x[], int s, int e, int m);

template <class T>
void msort1(T a[], T x[], int  s, int e) {
	int m;
	if (s < e) {
		m = (s + e) / 2;
		msort1(a, x, s, m);
		msort1(a, x, m + 1, e);
		merge(a, x, s, e, m);
	}
}

template <class T>
void merge(T a[], T x[], int  s, int e, int m) {
	int i, k, j;
	i = s;
	k = s;
	j = m + 1;
	while (i <= m && j <= e) {
		if (a[i] < a[j]) {
			x[k] = a[i];
			++i;
		} else {
			x[k] = a[j];
			j++;
		}
		k++;
	}
	while (i > m && j <= e) {
		x[k] = a[j];
		k++; j++;
	}
	while (j > e && i <= m) {
		x[k] = a[i];
		++i; ++k;
	}
	for (int l = s; l <= e; ++l) {
		a[l] = x[l];
	}
}

template <class T>
void mergesort(T a[], int n) {
	int *x;
	x = new int[n];
	msort1(a, x, 0, n - 1);
	delete[] x;
}

template <class T>
bool sorted(T a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		if (a[i + 1] < a[i]) return false;
	}
	return true;
}

int main(int argc, char * args[]) {
	int p[] = { 5, 3, 11, 9 };
	int s[] = { 8, 4, 9, 2, 0 };
	mergesort(p, 4);
	mergesort(s, 5);

	int a[1000];
	for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
	mergesort(a, 1000);
	assert(sorted(a, 1000));

	int b[1001];
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergesort(b, 1001);
	assert(sorted(b, 1001));

	int c[] = { 2 };
	mergesort(c, 1);
	assert(sorted(c, 1));

	int d[] = { 1, 2, 3, 4, 5 };
	mergesort(d, 5);
	assert(sorted(d, 5));
	assert(sorted(a, 4) == true);
	assert(sorted(b, 5) == true);

	cout << "All tests passed." << endl;
}
