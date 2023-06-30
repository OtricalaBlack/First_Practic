#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "RUS");

    int size_mas = 0;
    int* unsert_mas;
    int max_num;
    int min_num;

    printf("Размер множества: ");
    scanf("%d", &size_mas);

    unsert_mas = (int*)malloc(size_mas * sizeof(int));

    printf("\nМинимальное число: ");
    scanf("%d", &min_num);

    printf("\nМаксимальное число: ");
    scanf("%d", &max_num);

    for (int i = 0; i < size_mas; i++) {
        if (min_num >= 0) {
            unsert_mas[i] = rand() % max_num;
        }
        else {
            unsert_mas[i] = min_num + rand() % max_num;
        }
    }

	printf("\nнеотсортированный массив:\n");
	for (int i = 0; i < size_mas; i++) {
		printf("%d ", unsert_mas[i]);
	}
	printf("\n");

    for (int i = 1; i < size_mas; i++) {
        int j = i;
        while (j > 0 && unsert_mas[j - 1] > unsert_mas[j]) {
            int tmp = unsert_mas[j - 1];
            unsert_mas[j - 1] = unsert_mas[j];
            unsert_mas[j] = tmp;
            j--;
        }
    }

	printf("\nотсортированный массив:\n");
	for (int i = 0; i < size_mas; i++) {
		printf("%d ", unsert_mas[i]);
	}
	printf("\n");

    getch();

    return 0;
}