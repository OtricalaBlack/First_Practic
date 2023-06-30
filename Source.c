#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>

// Функция, выводящая таблицу с названием программы 
void print_name()
{
	printf("\t\t\t\t\t\t  +-------------------------+\n");
	printf("\t\t\t\t\t\t  |   Сортировка вставкой   |\n");
	printf("\t\t\t\t\t\t  +-------------------------+\n");
	printf("\n\n\n\n");
}

// Функция, выводящая таблицу с введенными данными пользователя и итоговое время сортировки 
void last_table(size_mas, max_num, min_num, time_end)
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
int main()
{
	srand(time(NULL)); // Подключение случайных чисел 

	setlocale(LC_ALL, "RUS"); // Подключение русского языка 

	print_name(); // Вывод первой таблицы 

	int size_mas; // Размер множества
	int* unsert_mas; // Указатель для расширение памяти
	int max_num; // Минимальное число
	int min_num; // Максимальное число 
	char file1[20] = "unsert_mas_file"; // Имя файла не отсортированного множества 
	char file2[20] = "sert_mas_file"; // Имя файла отсортированного множества 


	printf("Размер множества: ");
	scanf("%d", &size_mas); // Ввод размера множества 

	unsert_mas = (int*)malloc(size_mas * sizeof(int)); // Расширение памяти

	printf("\n");

	printf("Минимальное число: ");
	scanf("%d", &min_num); // Ввод минимального числа в множестве

	printf("\n");

	printf("Максимальное число: ");
	scanf("%d", &max_num); // Ввод максимального числа в множестве

	printf("\n");

	// Заполнение файла не отсортированным множеством 
	FILE* file_1 = fopen(file1, "w");
	for (int i = 0; i < size_mas; i++)
	{
		if (min_num >= 0)
		{
			fprintf(file_1, "%5d", unsert_mas[i] = rand() % max_num); // Если минимальное число положительное 
		}
		else
		{
			fprintf(file_1, "%5d", unsert_mas[i] = min_num + rand() % max_num); // Если минимальное число отрицательное
		}
	}
	fclose(file_1);

	clock_t time_start = clock(); // Начало отсчета времени работы сортировки 

	char buf; // Буфер

	// Чтение из файла для сортировки 
	file_1 = fopen(file1, "r");
	while ((buf = fgetc(file_1)) != EOF) // До конца файла 
	{
		for (int i = 0; i < size_mas + 1; i++) {
			if (i == ' ') {
				continue; // Без ' '
			}
			else {
				fscanf(file_1, "%5d", &unsert_mas[i]);
			}
		}
	}
	fclose(file_1);

	// Сортировка 
	for (int i = 1; i < size_mas + 1; i++)
	{
		int j = i; // Текущие расположение 
		while (j > 0 && unsert_mas[j - 1] > unsert_mas[j]) // Пока слева есть место и элемент слева больше элемента справа 
		{
			// Смена мест 
			int tmp = unsert_mas[j - 1];
			unsert_mas[j - 1] = unsert_mas[j];
			unsert_mas[j] = tmp;
			j--;
		}
	}

	// Запись в файл отсортированного множества 
	FILE* file_2 = fopen(file2, "w");
	for (int i = 1; i < size_mas + 1; i++)
	{
		fprintf(file_2, "%5d", unsert_mas[i]);
	}
	fclose(file_2);

	clock_t time_end = clock() - time_start; // Конец отсчета времени 

	system("cls"); // Очистка консоли 

	print_name(); //  Вывод первой таблицы 

	last_table(size_mas, max_num, min_num, time_end); // Вывод второй таблицы

	return 0;
}