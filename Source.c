#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");

	int size_mas = 0;
	int* unsert_mas;
	int max_num;
	int min_num;

	printf("Размер множества: ");
	scanf("%d", &size_mas);

	unsert_mas = (int*)malloc(size_mas * sizeof(int));

	printf("\n");

	printf("Минимальное число: ");
	scanf("%d", &min_num);

	printf("\n");

	printf("Максимальное число: ");
	scanf("%d", &max_num);
	return 0;
}