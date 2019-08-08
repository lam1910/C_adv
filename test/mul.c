#include <stdio.h>
#include <stdlib.h>

#define R 1000000007

int n, M;
int* arr;

void init()
{
  int i;
  scanf("%d%*c%d\n", &n, &M);
  arr = (int* )malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    {
      scanf("%d%*c", arr + i);
    }
}

//(x + y) mod P
int addMod(int x, int y, int P)
{
  if (x >= 0)
    {
      x = x % P;
      y = y % P;
      int tmp = P - x;
      if (tmp > y)
	return (x + y);
      else
	return (y - tmp);
    }
  else if (y >= 0)
    return addMod(y, x, P);
  else
    return (- addMod(-x, -y, P));
}

void solve()
{
  int i, j, result;
  result = 0;
  for (i = 0; i < n - 1; i ++)
    {
      for (j = i + 1; j < n; j ++)
	{
	  if (*(arr + i) + *(arr + j) <= M)
	    result = addMod(result, 1, R);
	}
    }
  printf("%d\n", result);
}

int main()
{
  init();
  solve();
  return 0;
}
