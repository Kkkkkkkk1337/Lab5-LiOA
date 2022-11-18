#include <stdio.h>
#include <windows.h>
#include <time.h>

void podschet(int n, int** G)
{
	int razm = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (G[i][j] != 0)
			{
				razm++;
			}
		}
	}
	printf("Размер графа = %d\n\n", razm);
}

void poisk(int n, int** G)
{
	for (int i = 0; i != n; i++)
	{
		int s = 0; // кол-во ребер с данной вершиной
		for (int j = 0; j != n; j++)
		{
			if (G[i][j] == 1)
			{
				s++;
			}
		}
		if (s == 0)
		{
			printf("Вершина %d изолированная\n", i + 1);
		}
		else if (s == 1)
		{
			printf("Вершина %d концевая\n", i + 1);
		}

		else if (s == (n - 1))
		{
			printf("Вершина %d доминирующая\n", i + 1);
		}

		else
		{
			printf("Вершина %d просто вершина\n", i + 1);
		}
	}
}

int main(void)
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int** G;
	int n;
	printf("Введите n = ");
	scanf_s("%d", &n);
	G = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			G[i][j] = rand() % 2;
			if (i == j)
			{
				G[i][j] = 0;
			}
			G[j][i] = G[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", G[i][j]);
		}
		printf("\n");
	}
	podschet(n, G);
	poisk(n, G);
}