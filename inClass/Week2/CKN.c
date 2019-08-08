#include <stdio.h>
#include <stdlib.h>

#define x 1000000007
/*unsigned long long int factorial(unsigned long long int a)
{
  if (a == 1)
    return a;
  else
    return a * factorial(a - 1);
}

unsigned long long int CKN(unsigned long long int k, unsigned long long int n)
{
  if (k > n)
    return -1;
  else
    {
      unsigned long long int fK, fN, fKN, result;
      fK = factorial(k);
      fN = factorial(n);
      fKN = factorial(n - k);
      result = fN / (fK * fKN);
      return result;
    }
    }*/

long long m[1000][1000];
long long addmod(long long a, long long b)
{
  a = a % x;
  b = b % x;
  long long tmp = x - b;
  if (a >= tmp)
    return a - tmp;
  else
    return a + b;
}

void init()
{
  int i, j;
  for (i = 0; i < 1000; i ++)
    for (j = 0; j < 1000; j ++)
      m[i][j] = -1;
}

long long C(int k, int n)
{
  if (k == 0 || k == n)
    m[k][n] = 1;
  else
    {
      if (m[k][n] < 0)
	{
	  int a = C(k-1, n - 1);
	  int b = C(k, n - 1);
	  m[k][n] = addmod(a, b);
	}
    }
  return m[k][n];
}

int main()
{
  int k, n;
  init();
  scanf("%d%*c%d", &k, &n);
  printf("k = %d\nn = %d\n", k, n);
  printf("%lld\n", C(k, n));  
  return 0;
}
