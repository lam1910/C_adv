#include <stdio.h>
#include <stdlib.h>

#define MAX 4000

int n, m, result;

//adjacent list
int z[MAX + 1];

//adjacent matrix;
int A[MAX + 1][MAX + 1];

//matrix edge
int E[MAX + 1][MAX + 1];

void init()
{
  int i, j, u, v;
  for (i = 0; i <= MAX; i++)
  {
    z[i] = 0;
    for(j = 0; j <= MAX; j ++)
      A[i][j] = 0;   
  }
  scanf("%d%*c%d\n", &n, &m);
  for (i = 0; i < m; i ++)
    {
      scanf("%d%*c%d%*c", &u, &v);
      z[u] ++;
      A[u][z[u] - 1] = v;
      z[v] ++;
      A[v][z[v] - 1] = u;
      E[u][v] = 1;
    }
}

void solve()
{
  result = 0;
  int a, b ,c, i, j, k;
  for (a = 1; a <= n; a ++)
    {
      for (i = 0; i < z[a]; i ++)
	{
	  b = A[a][i];
	  for (j = 0; j < z[b]; j ++)
	    {
	      c = A[b][j];
	      if (E[a][c] == 1)
		result ++;
	    }
	}
    }
  printf("%d\n", result / 3);
}

int main()
{
  init();
  solve();
  return 0;
}
