#include <stdio.h>
#include <stdlib.h>

int n, excellent, noExcellent;
int* examOne;
int* examTwo;

void init()
{
  int i;
  scanf("%d\n", &n);
  examOne = (int* )malloc(n * sizeof(int));
  examTwo = (int* )malloc(n * sizeof(int));

  for (i = 0; i < n; i ++)
    scanf("%d%*c%d%*c", examOne + i, examTwo + i);
}

//check whether a is better than b
//return 1 if a > b, 0 if a isn't better b, -1 if a < b, -2 if either a or b > n
int superiorStudent(int a, int b)
{
  if (a > n || b > n)
    return -2;
  else if ((*(examOne + a) < *(examOne + b)) && (*(examTwo + a) < *(examTwo + b)))
    return -1;
  else if ((*(examOne + a) > *(examOne + b)) && (*(examTwo + a) > *(examTwo + b)))
    return 1;
  else
    return 0;
}

void solve()
{
  int i;
  excellent = 0;
  noExcellent = 1;
  for (i = 1; i < n; i ++)
    {
      if (superiorStudent(i, excellent) == 1)
	{
	  excellent = i;
	  noExcellent = 1;
	}
      else if (superiorStudent(i, excellent) == 0)
	noExcellent ++;
      else
	continue;
    }
  printf("%d\n", noExcellent);
}

int main()
{
  init();
  solve();
  return 0;
}
