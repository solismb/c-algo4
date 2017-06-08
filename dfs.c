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

void visit(int i, int v[N], int G[N][N], int n)
{
	int j;

	v[i] = 1;
	for (j = 0; j < n; j++) {
		if (G[i][j] == 1 && v[j] == 0) {
			printf("%d => %d ", i, j);
			visit(j, v, G, n);
		}
	}

	printf("\n");
}

int main()
{
	int n, s, G[N][N], v[N];

	printf("点の数: ");
	scanf("%d", &n);

	initArr(v, G, n);
	
	getData(G);
	printArr(G, n);
	
	printf("始点: ");
	scanf("%d", &s);
	visit(s, v, G, n);

	return 0;
}
