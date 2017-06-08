#include <stdio.h>
#include <time.h>
#define N 2000000

void getData(int A[], int n)
{
	int i;
	FILE *fp;

	fp = fopen("data.txt", "r");

	for (i = 0; i < n; i++)
		fscanf(fp, "%d", &A[i]);

	fclose(fp);

	return;
}

void swap(int *s, int *t)
{
	int temp;

	temp = *s;
	*s = *t;
	*t = temp;

	return;
}

void bubble(int A[], int n)
{
	int i, j, flag = 0;

	for (i = 0; i < n; i++) {
		flag = 0;
		for (j = n - 1; j > i; j--) {
			if (A[j] < A[j - 1]) {
				swap(&A[j], &A[j - 1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}

	return;
}

void printAns(int A[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%6d ", A[i]);
	puts("");

	return;
}

int main()
{
	int A[N], n;
	FILE *fp;

	clock_t before;
	double elapsed;

	printf("データ数: ");
	scanf("%d", &n);

	getData(A, n);

	before = clock();
	bubble(A, n);
	elapsed = (clock() - before) / CLOCKS_PER_SEC;
	
	//printAns(A, n);
	
	fp = fopen("time4.csv", "a");

	fprintf(fp, "\n bubble: n time(s)\n %d, %lf, ", n, elapsed);

	fclose(fp);

	return 0;
}
