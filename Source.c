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
void last_table(int size_mas, int max_num, int min_num, int time_end)
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
	printf("\t\t\t\t      |    Время сортировки    | %14lf(c)      |\n", (double)time_end / CLOCKS_PER_SEC);
	printf("\t\t\t\t      +------------------------+------------------------+\n");
	
}

// Функция сортировки
void insertion_sort(int size_mas, int* unsort_mas) 
{
	// Сортировка 
	for (int i = 1; i < size_mas + 1; i++)
	{
		// Текущие расположение 
		int j = i; 
		// Пока слева есть место и элемент слева больше элемента справа 
		while (j > 0 && unsort_mas[j - 1] > unsort_mas[j]) 
		{
			// Смена мест 
			int tmp = unsort_mas[j - 1];
			unsort_mas[j - 1] = unsort_mas[j];
			unsort_mas[j] = tmp;
			j--;
		}
	}
}

// Основная функция 
int main()
{
	// Подключение случайных чисел 
	srand(time(NULL)); 

	// Подключение русского языка 
	setlocale(LC_ALL, "RUS"); 

	// Вывод первой таблицы 
	print_name(); 

	int size_mas; // Размер множества
	int* unsort_mas; // Указатель для расширение памяти
	int max_num; // Минимальное число
	int min_num; // Максимальное число 
	char have_file; // Для проверки на наличие пользавотельского файла 
	char buf; // Буфер
	char name1[20]; // Имя файла не отсортированного множества 
	char name2[20]; // Имя файла отсортированного множества 

	// Подтверждение или отрицание наличия файла 
	printf("Есть файл для сортировки? (Для подтверждения введите Y/y, если нет, то введите N/n, программа будет работать со случайными числами): ");
	scanf("%c", &have_file);

	printf("\n");

	// Если введено не "Y\yes", то заполнением файла псевдослучайными числами 
	if (have_file != 'Y' && have_file != 'y')
	{
		// Имя файла для не отсортированного множества
		printf("В каком файле сохранить не отсортированное множество?: ");
		scanf("%s", &name1);

		printf("\n");

		// Имя файла для отсортированного множества
		printf("В каком файле сохранить отсортированное множество?: ");
		scanf("%s", &name2);

		printf("\n");

		// Ввод размера множества
		printf("Размер множества: ");
		scanf("%d", &size_mas); 

		printf("\n");

		// Ввод нижнего предела множества 
		printf("Минимальное число: ");
		scanf("%d", &min_num); 

		printf("\n");

		// Ввод верхнего предела множества 
		printf("Максимальное число: ");
		scanf("%d", &max_num); 

		printf("\n");

		// Расширение памяти
		unsort_mas = (int*)malloc(size_mas * sizeof(int)); 

		// Заполнение файла не отсортированным множеством 
		FILE* file_1 = fopen(name1, "w");
		for (int i = 0; i < size_mas; i++)
		{
			if (min_num >= 0)
			{
				// Если минимальное число положительное 
				fprintf(file_1, "%5d", unsort_mas[i] = rand() % max_num); 
			}
			else
			{
				// Если минимальное число отрицательное
				fprintf(file_1, "%5d", unsort_mas[i] = min_num + rand() % max_num);
			}
		}
		fclose(file_1);

		// Начало отсчета времени работы сортировки 
		clock_t time_start = clock(); 

		// Чтение из файла для сортировки 
		file_1 = fopen(name1, "r");
		// До конца файла 
		while ((buf = fgetc(file_1)) != EOF) 
		{
			for (int i = 0; i < size_mas + 1; i++) {
				if (i == ' ') {
					// Без ' '
					continue; 
				}
				else {
					fscanf(file_1, "%5d", &unsort_mas[i]);
				}
			}
		}
		fclose(file_1);

		// Вызов функции, которая отвечает за алгоритм сортировки 
		insertion_sort(size_mas, unsort_mas);

		// Запись в файл отсортированного множества 
		FILE* file_2 = fopen(name2, "w");
		for (int i = 1; i < size_mas + 1; i++)
		{
			fprintf(file_2, "%5d", unsort_mas[i]);
		}
		fclose(file_2);

		// Конец отсчета времени 
		clock_t time_end = clock() - time_start; 

		// Очистка консоли 
		system("cls"); 

		// Вывод первой таблицы 
		print_name(); 

		// Вывод второй таблицы
		last_table(size_mas, max_num, min_num, time_end); 
	}
	// Второй сценарий, если у пользователя есть файл для сортировки 
	else 
	{
		// Ввод имени пользовательского файла для сортировки 
		printf("Какой файл необходимо отсортировать?: ");
		scanf("%s", &name1);

		printf("\n");

		// Проверка на наличие файла
		FILE* file_1 = fopen(name1, "r");
		while (!file_1)
		{
			char next[4]; // Выход из программы 
			printf("Ошибка: файл с таким именем не найден!");

			printf("\n\n");

			// Если пользавотель захочет прекратить попытки ввода корректного имени файла
			printf("Продолжить? (Ввдите \"Yes/yes\", если хотите продолжить): ");
			scanf("%s", &next);

			printf("\n");

			// Если пользавотель введет не "Yes\yes", то выход из програамы
			if (next[0] != 'Y' && next[0] != 'y')
			{
				return 1;
			}
			// Если после неудачной попытки, введет корректное имя файла
			else
			{
				printf("Какой файл необходимо отсортировать?: ");
				scanf("%s", &name1);

				printf("\n");

				file_1 = fopen(name1, "r");
			}
			fclose(file_1);
		}
		fclose(file_1);

		// Сохранение длины файла
		file_1 = fopen(name1, "r");
		fseek(file_1, 0L, SEEK_END);
		size_mas = ftell(file_1);
		fclose(file_1);

		// если файл пуст
		if (size_mas == 0)
		{
			printf("Ошибка: Файл пуст!");
			printf("\n");
			return 1;
		}
		else 
		{
			// Ввод имени файла для сохранения отсортированного множества
			printf("В каком файле сохранить отсортированное множество?: ");
			scanf("%s", &name2);

			// Расширение памяти
			unsort_mas = (int*)malloc(size_mas * sizeof(int)); 

			// Начало отсчета времени работы сортировки 
			clock_t time_start = clock(); 

			// Чтение из файла для сортировки 
			file_1 = fopen(name1, "r");
			// До конца файла 
			while ((buf = fgetc(file_1)) != EOF) 
			{
				for (int i = 0; i < size_mas + 1; i++) {
					if (i == ' ') {
						// Без ' '
						continue; 
					}
					else {
						fscanf(file_1, "%d", &unsort_mas[i]);
					}
				}
			}
			fclose(file_1);

			// Вызов функции отвечающий за сортировку 
			insertion_sort(size_mas, unsort_mas);

			// Запись в файл отсортированного множества 
			FILE* file_2 = fopen(name2, "w");
			for (int i = 1; i < size_mas + 1; i++)
			{
				fprintf(file_2, "%5d", unsort_mas[i]);
			}
			fclose(file_2);

			// Конец отсчета времени 
			clock_t time_end = clock() - time_start; 

			// Очистка консоли 
			system("cls"); 

			// Вывод первой таблицы 
			print_name();

			// Вывод времени потраченного на сортировку 
			printf("\t\t\t\t      +------------------------+------------------------+\n");
			printf("\t\t\t\t      |    Время сортировки    | %14lf(c)      |\n", (double)time_end / CLOCKS_PER_SEC);
			printf("\t\t\t\t      +------------------------+------------------------+\n");
		}
	}
	// Освобождение памяти 
	free(unsort_mas);
	return 0;
}