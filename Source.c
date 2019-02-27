#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Element
{
	int key;
}element;
int nBreak = 5000;

void insertionSort(element a[], int n);
void insert(element e, element a[], int i);
void quickSort(element a[], int left, int right);
void SWAP(element a, element b);
void insert_quick(element a[], int n);

int main() {
	int n, step = 10;
	element a[5001];
	clock_t start1, start2, start3;
	double duration1, duration2, duration3;
	srand(time(NULL));

	printf("%4s %18s %14s %18s\n", "N", "Insertion sort", "Quick sort", "Insertion quick");
	 
	for (n = 0; n <= 5000; n += step) {

		long repetitions1 = 0, repetitions2 = 0, repetitions3 = 0;

		start1 = clock();

		do {
			repetitions1++;
			for (int i = 0; i < n; i++) {
				a[i].key = rand();
			}
			insertionSort(a, n);
		} while (clock() - start1 < 1000);

		duration1 = ((double)(clock() - start1)) / CLOCKS_PER_SEC;
		duration1 /= repetitions1;

		start2 = clock();

		do {
			repetitions2++;
			for (int i = 0; i < n; i++) {
				a[i].key = rand();
			}
			quickSort(a, 0, n-1);
		} while (clock() - start2 < 1000);

		duration2 = ((double)(clock() - start2)) / CLOCKS_PER_SEC;
		duration2 /= repetitions2;

		int t = 0;
		if (repetitions2 > repetitions1 && n!=0 && t==0) {
			nBreak = n;
			t = 1;
		}

		start3 = clock();

		do {
			repetitions3++;
			for (int i = 0; i < n; i++) {
				a[i].key = rand();
			}
			insert_quick(a, n);
		} while (clock() - start3 < 1000);

		duration3 = ((double)(clock() - start3)) / CLOCKS_PER_SEC;
		duration3 /= repetitions3;

		printf("%4d %18f %14f %18f\n", n, duration1, duration2, duration3);

		if (n == 100) step = 100; 
		if (n == 1000) step = 1000; 
	}

	return 0;
}

void SWAP(element a, element b) {
	element temp;
	temp = a;
	a = b;
	b = temp;
}

void insertionSort(element a[], int n) {
	int j;
	element next;
	for (j = 2; j <= n; j++) {
		element temp = a[j];
		insert(temp, a, j - 1);
	}
}

void insert(element e, element a[], int i)
{	
	a[0] = e;
	while (e.key < a[i].key) {
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = e;
}

void quickSort(element a[], int left, int right)
{
	int pivot, i, j;
	if (left < right) {
		i = left;	j = right + 1;
		pivot = a[left].key;
		do {
			do
				i++;
			while (a[i].key < pivot);
			do
				j--;
			while (a[j].key > pivot);
			if (i < j)	SWAP(a[i], a[j]);
		} while (i < j);
		SWAP(a[left], a[j]);
		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);
	}
}

void insert_quick(element a[], int n) {
	if (n < nBreak) insertionSort(a, n);
	else quickSort(a, 0, n - 1);
}
