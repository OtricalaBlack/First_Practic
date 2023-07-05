#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <time.h> 
#include <locale.h> 
#include <malloc.h> 
#include <stdlib.h> 
#include <stdbool.h>

// �������, ��������� ������� � ��������� ��������� 
void print_name()
{
	printf("\t\t\t\t\t\t  +-------------------------+\n");
	printf("\t\t\t\t\t\t  |   ���������� ��������   |\n");
	printf("\t\t\t\t\t\t  +-------------------------+\n");
	printf("\n\n\n\n");
}

// �������, ��������� ������� � ���������� ������� ������������ � �������� ����� ���������� 
void last_table(int size_mas, int max_num, int min_num, int time_end)
{

	printf("\t\t\t\t      +------------------------+------------------------+\n");
	printf("\t\t\t\t      |    ������ ���������    | %14d         |\n", size_mas);
	printf("\t\t\t\t      +------------------------+------------------------+\n");

	printf("\t\t\t\t      +------------------------+------------------------+\n");
	printf("\t\t\t\t      |    ����������� �����   | %13d          |\n", min_num);
	printf("\t\t\t\t      +------------------------+------------------------+\n");

	printf("\t\t\t\t      +------------------------+------------------------+\n");
	printf("\t\t\t\t      |   ������������ �����   | %13d          |\n", max_num);
	printf("\t\t\t\t      +------------------------+------------------------+\n");

	printf("\t\t\t\t      +------------------------+------------------------+\n");
	printf("\t\t\t\t      |    ����� ����������    | %14lf(c)      |\n", (double)time_end / CLOCKS_PER_SEC);
	printf("\t\t\t\t      +------------------------+------------------------+\n");

}

// ������� ����������
void insertion_sort(int size_mas, int* unsort_mas)
{
	// ���������� 
	for (int i = 1; i < size_mas; i++)
	{
		// ������� ������������ 
		int j = i;
		// ���� ����� ���� ����� � ������� ����� ������ �������� ������ 
		while (j > 0 && unsort_mas[j - 1] > unsort_mas[j])
		{
			// ����� ���� 
			int tmp = unsort_mas[j - 1];
			unsort_mas[j - 1] = unsort_mas[j];
			unsort_mas[j] = tmp;
			j--;
		}
	}
}

// �������� ������� 
int main()
{
	// ����������� ��������� ����� 
	srand(time(NULL));

	// ����������� �������� ����� 
	setlocale(LC_ALL, "RUS");

	// ����� ������ ������� 
	print_name();

	int size_mas; // ������ ���������
	int* unsort_mas; // ��������� ��� ���������� ������
	int max_num; // ����������� �����
	int min_num; // ������������ ����� 
	char have_file; // ��� �������� �� ������� ����������������� ����� 
	char buf; // �����
	char name1[20]; // ��� ����� �� ���������������� ��������� 
	char name2[20]; // ��� ����� ���������������� ��������� 
	int counter = 0;

	// ������������� ��� ��������� ������� ����� 
	printf("���� ���� ��� ����������? (��� ������������� ������� Y/y, ���� ���, �� ������� N/n, ��������� ����� �������� �� ���������� �������): ");
	scanf("%c", &have_file);

	printf("\n");

	// ���� ������� �� "Y\yes", �� ����������� ����� ���������������� ������� 
	if (have_file != 'Y' && have_file != 'y')
	{
		// ��� ����� ��� �� ���������������� ���������
		printf("� ����� ����� ��������� �� ��������������� ���������?: ");
		scanf("%s", &name1);

		printf("\n");

		// ��� ����� ��� ���������������� ���������
		printf("� ����� ����� ��������� ��������������� ���������?: ");
		scanf("%s", &name2);

		printf("\n");

		// ���� ������� ���������
		printf("������ ���������: ");
		scanf("%d", &size_mas);

		printf("\n");

		// ���� ������� ������� ��������� 
		printf("����������� �����: ");
		scanf("%d", &min_num);

		printf("\n");

		// ���� �������� ������� ��������� 
		printf("������������ �����: ");
		scanf("%d", &max_num);

		printf("\n");

		// ���������� ������
		unsort_mas = (int*)malloc(size_mas * sizeof(int));

		// ���������� ����� �� ��������������� ���������� 
		FILE* file_1 = fopen(name1, "w");
		for (int i = 0; i < size_mas; i++)
		{
			if (min_num >= 0)
			{
				// ���� ����������� ����� ������������� 
				fprintf(file_1, "%5d", unsort_mas[i] = rand() % max_num);
			}
			else
			{
				// ���� ����������� ����� �������������
				fprintf(file_1, "%5d", unsort_mas[i] = min_num + rand() % max_num);
			}
		}
		fclose(file_1);

		// ������ ������� ������� ������ ���������� 
		clock_t time_start = clock();

		// ������ �� ����� ��� ���������� 
		file_1 = fopen(name1, "r");
		// �� ����� ����� 
		while ((buf = fgetc(file_1)) != EOF)
		{
			for (int i = 0; i < size_mas; i++)
			{
				fscanf(file_1, "%5d", &unsort_mas[i]);
			}
		}
		fclose(file_1);
		// ����� �������, ������� �������� �� �������� ���������� 
		insertion_sort(size_mas, unsort_mas);

		// ������ � ���� ���������������� ��������� 
		FILE* file_2 = fopen(name2, "w");
		for (int i = 0; i < size_mas; i++)
		{
			fprintf(file_2, "%5d", unsort_mas[i]);
		}
		fclose(file_2);

		// ����� ������� ������� 
		clock_t time_end = clock() - time_start;

		// ������� ������� 
		system("cls");

		// ����� ������ ������� 
		print_name();

		// ����� ������ �������
		last_table(size_mas, max_num, min_num, time_end);
	}
	// ������ ��������, ���� � ������������ ���� ���� ��� ���������� 
	else
	{
		// ���� ����� ����������������� ����� ��� ���������� 
		printf("����� ���� ���������� �������������?: ");
		scanf("%s", &name1);

		printf("\n");

		// �������� �� ������� �����
		FILE* file_1 = fopen(name1, "r");
		while (!file_1)
		{
			char next[4]; // ����� �� ��������� 
			printf("������: ���� � ����� ������ �� ������!");

			printf("\n\n");

			// ���� ������������ ������� ���������� ������� ����� ����������� ����� �����
			printf("����������? (������� \"Yes/yes\", ���� ������ ����������): ");
			scanf("%s", &next);

			printf("\n");

			// ���� ������������ ������ �� "Yes\yes", �� ����� �� ���������
			if (next[0] != 'Y' && next[0] != 'y')
			{
				return 1;
			}
			// ���� ����� ��������� �������, ������ ���������� ��� �����
			else
			{
				printf("����� ���� ���������� �������������?: ");
				scanf("%s", &name1);

				printf("\n");

				file_1 = fopen(name1, "r");
			}
			fclose(file_1);
		}
		fclose(file_1);

		// ���������� ���-�� ����� 
		file_1 = fopen(name1, "r");
		fseek(file_1, 0, SEEK_SET);
		while(true) 
		{
			int val;
			if (fscanf(file_1, "%d", &val) == 1) 
			{
				counter++;
			}
			if (feof(file_1)) 
			{
				break;
			}
		}
		fclose(file_1);

		size_mas = counter;

		// ���� ���� ����
		if (size_mas == 0)
		{
			printf("������: ���� ����!");
			printf("\n");
			return 1;
		}
		else
		{
			// ���� ����� ����� ��� ���������� ���������������� ���������
			printf("� ����� ����� ��������� ��������������� ���������?: ");
			scanf("%s", &name2);

			// ���������� ������
			unsort_mas = (int*)malloc(size_mas * sizeof(int));

			// ������ ������� ������� ������ ���������� 
			clock_t time_start = clock();

			// ������ �� ����� ��� ���������� 
			file_1 = fopen(name1, "r");
			fseek(file_1, 0, SEEK_SET);
			for (int i = 0; i < size_mas; ++i) {
				fscanf(file_1, "%d", &unsort_mas[i]);
			}
			fclose(file_1);

			// ����� ������� ���������� �� ���������� 
			insertion_sort(size_mas, unsort_mas);

			// ������ � ���� ���������������� ��������� 
			FILE* file_2 = fopen(name2, "w");
			for (int i = 0; i < size_mas; ++i)
			{
				fprintf(file_2, "%5d", unsort_mas[i]);
			}
			fclose(file_2);

			// ����� ������� ������� 
			clock_t time_end = clock() - time_start;

			// ������� ������� 
			system("cls");

			// ����� ������ ������� 
			print_name();

			// ����� ������� ������������ �� ���������� 
			printf("\t\t\t\t      +------------------------+------------------------+\n");
			printf("\t\t\t\t      |    ����� ����������    | %14lf(c)      |\n", (double)time_end / CLOCKS_PER_SEC);
			printf("\t\t\t\t      +------------------------+------------------------+\n");
		}
	}
	return 0;
}