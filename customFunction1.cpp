#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void printArr(int** masA, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf(" %d ", *(*(masA + i) + j));
		}
		printf("\n");
	}
}

void initArray(int**& masA, int n, int m) {

	masA = new int* [n];
	for (int i = 0; i < n; i++) {
		*(masA + i) = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			*(*(masA + i) + j) = 1 + rand() % 100;
		}
	}
}

void changeDiagonal(int**& masA, int n) {

	int temp;
	for (int i = 0; i < n / 2; i++) {
		temp = *(*(masA + i) + i);
		*(*(masA + i) + i) = *(*(masA + n - i - 1) + n - i - 1);
		*(*(masA + n - i - 1) + n - i - 1) = temp;
	}
}

void main() {
	int n, m;
	int** masA;

	m0:
	printf("Enter the number of lines: ");
	scanf("%d", &n);
	printf("\nEnter the number of columns: ");
	scanf("%d", &m);

	while (n != m || n <= 2 || m <= 2) {
		printf("\nException - enter the same quantity lines and columns more than two\n");
		goto m0;
	}

	srand(time(NULL));

	masA = new int* [n];
	for (int i = 0; i < n; i++) {
		*(masA + i) = new int[m];
	}

	printf("\n matrix up: \n");
	initArray(masA, n, m);
	printArr(masA, n, m);

	printf("\n matrix after: \n");
	changeDiagonal(masA, n);
	printArr(masA, n, m);
}