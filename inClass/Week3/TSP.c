#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MCOST 1000000000

int n, m;
int c[MAX][MAX];
int cmin;
int visited[MAX];
int x[MAX];
int x_best[MAX];
int f;
int f_best = MCOST;

void init()
{
  int i, j, k;
  scanf("%d %d%*c", &n, &m);
  for (i = 0; i < n; i ++)
    {
      for (j = 0; j < n; j ++)
	{
	  c[i][j] = MCOST;
	  if (i == j)
	    c[i][j] = 0;
	}
    }
  cmin = MCOST;
  
  for (k = 0; k < m; k ++)
    {
      int w;
      scanf("%d%*c%d%*c%d%*c", &i, &j, &w);
      c[i][j] = w;
      if (w < cmin)
	cmin = w;
    }
}

void solution()
{
  int i;
  if (f + c[x[n]][x[1]] < f_best)
    {
      f_best = f + c[x[n]][x[1]];
      
    }
  for (i = 1; i <= n; i ++)
    x_best[i] = x[i];
}

void TRY(int k)
{
  int v;
  for (v = 1; v <= n; v ++)
    {
      if (!visited[v])
	{
	  x[k] = v;
	  visited[v] = 1;
	  f = f + c[x[k - 1]][x[k]];
	  if (k == n)
	    solution();
	  else
	    {
	      int g = f + (n - k + 1) * cmin;
	      if (g < f_best)
		TRY(k + 1);
	    }
	  visited[v] = 0;
	  f = f - c[x[k - 1]][x[k]];
	}
    }
}

int main()
{
  init();
  x[1] = 1;
  visited[x[1]] = 1;
  TRY(2);
  printf("%d\n", f_best);
  return 0;
}
