#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#pragma warning(disable : 4996)

void scanN(FILE* a, int* n)
{
  fscanf(a, "n = %d\n", n);
}

void inizmas(int n, float* mas)
{
  int i;
  for (i = 0; i < n; i++)
  {
    mas[i] = 0;
  }
}

void scanmas(FILE* a, int n, float* mas)
{
  int i;
  for (i = 0; i < n; i++)
  {
    fscanf(a, "%f\n", &mas[i]);
  }
}

void printmas(int n, float* mas)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%f\n", mas[i]);
  }
}

void prisvoenie(float* mas, float* mas1, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    mas1[i] = mas[i];
  }
}

void puzyryok(int n, float* mas)
{
  int i, x;
  float p;
  for (i = 0; i < n; i++)
  {
    for (x = 0; x < n - i - 1; x++)
    {
      if (mas[x] > mas[x + 1])
      {
        p = mas[x];
        mas[x] = mas[x + 1];
        mas[x + 1] = p;
      }
    }
  }
}

void vstavka(int n, float* mas)
{
  int i, x;
  float p;
  for (i = 1; i < n; i++)
  {
    p = mas[i];
    for (x = i - 1; x >= 0; x--)
    {
      if (mas[x] < p)
      {
        break;
      }
      else
      {
        mas[x + 1] = mas[x];
      }
    }
    mas[x + 1] = p;
  }
}

void qSort(float* mas, int l, int u)
{
  int i = l, j = u;
  float t = 0;
  float x = mas[(int)(l + u) / 2];
  do
  {
    while (mas[i] < x)
      ++i;
    while (mas[j] > x)
      --j;
    if (i <= j)
    {
      t = mas[i];
      mas[i] = mas[j];
      mas[j] = t;
      i++;
      j--;
    }
  } while (i < j);
  if (l < j)
  {
    qSort(mas, l, j);
  }
  if (i < u)
  {
    qSort(mas, i, u);
  }
}


void bystraya(float* mas, int n)
{
  qSort(mas, 0, n - 1);
}


int main()
{
  int n, d = 0, y = 0;
  FILE* a = fopen("C:\\Users\\popov\\source\\repos\\prog 1\\mas.txt", "r");
  scanN(a, &n);
  float* mas = ((float*)malloc(n * sizeof(double)));
  float* mas1 = ((float*)malloc(n * sizeof(double)));
  inizmas(n, mas);
  inizmas(n, mas1);
  scanmas(a, n, mas);
  prisvoenie(mas, mas1, n);
  setlocale(LC_ALL, "Russian");
  printf("¬ыберите режим работы\n");
  printf("1 Ч напечатать массив\n");
  printf("2 Ч сортировать массив\n");
  printf("3 Ч сброс\n");
  printf("4 Ч выход из программы\n");
  while (d != 4)
  {
    scanf("%d", &d);
    if (d == 1)
    {
      printmas(n, mas);
    }
    else if (d == 2)
    {
      printf("¬ыберите тип сортировки\n");
      printf("1 Ч пузырек\n");
      printf("2 Ч вставкой\n");
      printf("3 Ч быстра€\n");
      while ((y != 1) && (y != 2) && (y != 3))
      {
        scanf("%d", &y);
        if (y == 1)
        {
          clock_t t1 = clock();
          puzyryok(n, mas);
          clock_t t2 = clock();
          printf("¬рем€ работы сортировки пузырьком Ч %lf секунд\n", ((double)(t2 - t1)) / CLOCKS_PER_SEC);
        }
        else if (y == 2)
        {
          clock_t t3 = clock();
          vstavka(n, mas);
          clock_t t4 = clock();
          printf("¬рем€ работы сортировки вставками Ч %lf секунд\n", ((double)(t4 - t3)) / CLOCKS_PER_SEC);
        }
        else if (y == 3)
        {
          clock_t t5 = clock();
          bystraya(mas, n);
          clock_t t6 = clock();
          printf("¬рем€ работы быстрой сортировки Ч %lf секунд\n", ((double)(t6 - t5)) / CLOCKS_PER_SEC);
        }
        else
        {
          printf("¬ведено неверное значение, повторите\n");
        }
      }
    }
    else if (d == 3)
    {
      prisvoenie(mas1, mas, n);
    }
    else if (d == 4)
    {
      printf("ѕрограмма закончила работу");
      return 0;
    }
    else
    {
      printf("¬ведите корректное значение\n");
    }
    y = 0;
  }
}