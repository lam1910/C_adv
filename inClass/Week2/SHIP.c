#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int d[MAX - 1];
int m[MAx][MAX];
int n, K, Q;

void input()
{
  int i = 0, j = 0;
  scanf("%d%*c%d%*c%d%*c", &n, &K, &Q);
  for (i = 0; i < n; i ++)
    scanf("%d%*c", &d[i]);
  for (i = 0; i < n; i ++)
    for (j = 0; j < n; j ++)
      scanf("%d%*c", &m[i][j]);
}



int main()
{
  input();
  return 0;
}
