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

void numerOfLines(int**& masA, int n, int m) {

	int kolElements = 0;
	int kolStrok = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (*(*(masA + i) + j) == 0) {
				kolElements++;
			}
		}
		if (kolElements == 0) {
			kolStrok++;
		}
		else {
			kolElements = 0;
		}
	}
	printf("\n The number of lines containing no null elements = %d \n", kolStrok);
}

void main() {
	int n, m;
	int** masA;

	m0:
	printf("Enter the number of lines: ");
	scanf("%d", &n);
	printf("\nEnter the number of columns: ");
	scanf("%d", &m);

	while (n <= 2 || m <= 2) {
		printf("\nException - enter the same quantity lines and columns more than two\n");
		goto m0;
	}

	srand(time(NULL));

	if (!(masA = (int**)malloc(sizeof(int*) * n))) {
		printf("Not enough memory!\n");
		exit(0);
	}

	for (int i = 0; i < n; i++) {
		if (!(*(masA + i) = (int*)malloc(sizeof(int) * m)))
		{
			printf("Not enough memory!\n");
			masA = NULL;
			exit(0);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			*(*(masA + i) + j) = rand() % 100;
		}
	}

	printArr(masA, n, m);
	numerOfLines(masA, n, m);	
}
