#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#pragma warning(disable : 4996)

int main()
{
	int n, i;
	double max, min;
	printf("n: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("Error, n <= 0");
		return 0;
	}
	printf("min: ");
	scanf("%lf", &min);
	printf("max: ");
	scanf("%lf", &max);
	if (min > max)
	{
		printf("Error, min > max");
		return 0;
	}
	float* mas = ((float*)malloc(n * sizeof(float) + 1));
	for (i = 0; i < n; i++)
	{
		mas[i] = (((float)rand()) / RAND_MAX * (max - min) + min);
	}
	FILE* a = fopen("mas.txt", "w");
	fprintf(a, "n = %d\n", n);
	for (i = 0; i < n; i++)
	{
		fprintf(a, "%f\n", mas[i]);
	}
	fclose(a);
	free(mas);
	return 0;
}