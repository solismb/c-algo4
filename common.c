#include <stdio.h>
#define N 4

void initArr(int v[N], int G[N][N], int n)
{
		int i, j;

		for (i = 0; i < n; i++) {
				v[i] = 0;
				for (j = 0; j < n; j++) {
						G[i][j] = 0;
				}
		}
}

void printArr(int G[N][N], int n)
{
		int i, j;

		printf("\n\n ---G--- \n\n");
		for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
						printf("%d ", G[i][j]);
				}
				printf("\n");
		}
}

void getData(int G[N][N])
{
		int u = 0, v;

		printf("辺入力, 負の始点で終了\n");
		while (u >= 0) {
				printf("u, v: ");
				scanf("%d %d", &u, &v);
				if (u >= 0) {
						G[u][v] = 1;
						G[v][u] = 1;
				}
		}
}
