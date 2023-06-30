#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>

void function(time_start)
{
	clock_t time_end = clock() - time_start;
}

void print_name()
{
	printf("\t\t\t\t\t\t  +-------------------------+\n");
	printf("\t\t\t\t\t\t  |   Сортировка вставкой   |\n");
	printf("\t\t\t\t\t\t  +-------------------------+\n");
	printf("\n\n\n\n");
}

void last_table(int size_mas, int max_num, int min_num, clock_t time_end)
{
	printf("\t\t\t\t      +------------------------+------------------------+\n");
	printf("\t\t\t\t      |    Размер множества    | %14d         |\n", size_mas);
	printf("\t\t\t\t      +------------------------+------------------------+\n");

	printf("\t\t\t\t      +------------------------+------------------------+\n");
	printf("\t\t\t\t      |    Минимальное число   | %13d          |\n", min_num);
	printf("\t\t\t\t      +------------------------+------------------------+\n");

	printf("\t\t\t\t      +------------------------+------------------------+\n");
	printf("\t\t\t\t      |   Максимальное число   | %13d          |\n", max_num);
	printf("\t\t\t\t      +------------------------+------------------------+\n");

	printf("\t\t\t\t      +------------------------+------------------------+\n");
	printf("\t\t\t\t      |    Время сортировки    | %15lf        |\n", (double)time_end / CLOCKS_PER_SEC);
	printf("\t\t\t\t      +------------------------+------------------------+\n");

}

int main(time_end)
{
	srand(time(NULL));

	setlocale(LC_ALL, "RUS");

	print_name();

	int size_mas = 0;
	int* unsert_mas;
	int max_num;
	int min_num;
	char file1[20] = "unsert_mas_file";
	char file2[20] = "sert_mas_file";


	printf("Размер множества: ");
	scanf("%d", &size_mas);

	unsert_mas = (int*)malloc(size_mas * sizeof(int));

	printf("\n");

	printf("Минимальное число: ");
	scanf("%d", &min_num);

	printf("\n");

	printf("Максимальное число: ");
	scanf("%d", &max_num);

	printf("\n");

	FILE* file_1 = fopen(file1, "w");
	for (int i = 0; i < size_mas; i++)
	{
		if (min_num >= 0)
		{
			fprintf(file_1, "%5d", unsert_mas[i] = rand() % max_num);
		}
		else
		{
			fprintf(file_1, "%5d", unsert_mas[i] = min_num + rand() % max_num);
		}
	}
	fclose(file_1);

	char buf;
	file_1 = fopen(file1, "r");
	while ((buf = fgetc(file_1)) != EOF)
	{
		for (int i = 0; i < size_mas + 1; i++) {
			if (i == ' ') {
				continue;
			}
			else {
				fscanf(file_1, "%5d", &unsert_mas[i]);
			}
		}
	}
	fclose(file_1);

	clock_t time_start = clock();

	for (int i = 1; i < size_mas + 1; i++)
	{
		int j = i;
		while (j > 0 && unsert_mas[j - 1] > unsert_mas[j])
		{
			int tmp = unsert_mas[j - 1];
			unsert_mas[j - 1] = unsert_mas[j];
			unsert_mas[j] = tmp;
			j--;
		}
	}

	FILE* file_2 = fopen(file2, "w");
	for (int i = 1; i < size_mas + 1; i++)
	{
		fprintf(file_2, "%5d", unsert_mas[i]);
	}
	fclose(file_2);

	function(time_start);

	system("cls");

	print_name();

	last_table(size_mas, max_num, min_num, time_end);

	return 0;
}