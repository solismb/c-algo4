#include <stdio.h>
#include "common.c"
#define N 4

int main()
{
	int n, s, G[N][N], v[N];
	int i, j, front = 0, rear = 0, queue[100];
	
	printf("点の数: ");
	scanf("%d", &n);

	initArr(v, G, n);
	getData(G);
	printArr(G, n);

	printf("始点: ");
	scanf("%d", &s);

	queue[rear++] = s;
	v[s] = 1;

	do {
		i = queue[front++];

		for (j = 0; j < n; j++) {
			if (G[i][j] == 1 && v[j] == 0) {
				printf("%d => %d ", i, j);
				queue[rear++] = j;
				v[j] = 1;
			}
		}
	} while (front != rear);

	printf("\n\n");

	return 0;
}
