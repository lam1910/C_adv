#include <stdio.h>
#include <stdlib.h>

int reSum(int sum,  FILE* p, int i, int max)
{
  int n;
  if (i == max)
    return sum;
  else
    {
      fscanf(p, "%d%*c", &n);
      return reSum(sum + n, p, i + 1, max);
    }
}

int main()
{
  FILE* fptr, *fw;
  fptr = fopen("sequence.txt", "r+");
  fw = fopen("result.txt", "w+");
  if (fptr ==  NULL)
    {
      printf("Cannot open sequence.txt! Exit!\n");
      exit(1);
    }
  else if (fw == NULL)
    {
      printf("Cannot open result.txt! Exit!\n");
      exit(1);
    }
  else
    {
      int n, i, sum = 0, resum = 0;
      /*int* list;*/
      fscanf(fptr, "%d%*c", &n);
      /*list = (int* )malloc(n * sizeof(int));
      for (i = 0; i < n; i ++)
	{
	  fscanf(fptr, "%d%*c", &list[i]);
	  sum = sum + list[i];
	  }*/
      i = 0;
      resum = reSum(resum, fptr, i, n);
      /*free(list);
	printf("The sum of all elements is: %d\n", sum);*/
      printf("The sum of all elements recusively is: %d\n", resum);
      fprintf(fw, "%s%d\n", "The sum of all elements is:", sum);
    }
  fclose(fptr);
  fclose(fw);
  return 0;
}
