#include <stdio.h>
#include <stdlib.h>

#define N 1000000007

int n, b, result, temp;
int* arr;

//(x + y) mod P
int addMod(int x, int y, int P)
{
  x = x % P;
  y = y % P;
  int tmp = P - x;
  if (tmp > y)
    return (x + y);
  else
    return (y - tmp);
}


void init()
{
  scanf("%d %d%*c", &n, &b);
  arr = (int* )malloc(n * sizeof(int));
  int i;
  for (i = 0; i < n; i ++)
    {
      scanf("%d%*c", arr + i);
    }
}

//sum of all elements in an array that has n elements
int sumA(int* ar, int n)
{
  int i, sum;
  sum = 0;
  for (i = 0; i < n; i ++)
    sum = sum + *(ar + i);
  return sum;
}



void solve()
{
  int i;
  if (temp < b)
    result = -1;
  else if (temp == b)
    result = 1;
  else
    {
      int diff = temp - b;
      for (i = 0; i < n; i ++)
	{
	  if (arr[i] == diff)
	    result ++;
	  else if (arr[i] > diff)
	    break;
	  else if(arr[i] < diff)
	    {
	      temp -= arr[i];
	      diff -= arr[i];
	      solve();
	    }
	}
      temp += arr[i];
      diff += arr[i];
    }
}

int main()
{
  int i, j, a;
  init();
  for (i = 0; i < n; ++i)
    {      
      for (j = i + 1; j < n; ++j)	
	{ 
	  if (arr[i] > arr[j])
	    { 
	      a =  arr[i]; 
	      arr[i] = arr[j];
	      arr[j] = a;
	    }
	}
    }
  temp = sumA(arr, n);
  solve();
  printf("%d\n", result);
  free(arr);
  
  return 0;
}
