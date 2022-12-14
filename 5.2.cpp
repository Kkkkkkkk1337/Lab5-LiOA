#include <stdio.h>
#include <windows.h>
#include <time.h>

void poisk(int n, int** P, int M)
{
	for (int i = 0; i < n; i++)
	{
		int s = 0; // кол-во ребер с данной вершиной
		for (int j = 0; j < M; j++)
		{
			if (P[j][i] == 1)
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

void in(int n, int** G)
{
	int M = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (G[i][j] == 1)
			{
				M++;
			}
		}
	}
	M /= 2;
	printf("Размер графа = %d\n", M);
	int** P = (int**)malloc(M * sizeof(int*));
	for (int i = 0; i < M; i++)
	{
		P[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < n; j++)
		{
			P[i][j] = 0;
		}
	}
	int C = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (G[i][j])
			{
				P[C][i] = 1;
				P[C][j] = 1;
				C++;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", P[i][j]);
		}
		printf("\n");
	}
	poisk(n, P, M);
	free(P);
}

int main(void)
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n;
	printf("Введите n = ");
	scanf_s("%d", &n);
	int** G = (int**)malloc(n * sizeof(int*));
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
	printf("Матрица смежности:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", G[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Матрица инцидентности:\n");
	in(n, G);
	free(G);
	return 0;
}