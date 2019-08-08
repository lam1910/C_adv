/*#include <stdio.h>
#include <stdlib.h>

int n, m, M, A;
int a[10] = {0};
int x[10] = {0};

void input()
{
  int i;
  scanf("%d%*c%d%*c", &n, &M);
  for (i = 0; i < n; i ++)
    {
      scanf("%d%*c", &a[i]);
      printf("%d\n", a[i]);
    }
}
void printSolution()
{
  int i;
  for (i = 0; i < n; i ++)
    printf("%d ", x[i]);
}

void try(int k)
{
  int val;
  for (val = 1; val <= (M - m - A)/a[k]; val ++)
    {
      x[k] = val;
      m = m + a[k] * x[k];
      A = A - a[k];
      if (k == n)
	{
	  if (m == M)
	    printSolution();
	}
      else
	try(k + 1);
      m = m - a[k] * x[k];
      A = A + a[k];
    }
}

int main()
{
  input();
  int l;
  m = 0; A = 0;
  for (l = 0; l < n; l ++)
    A = A + a[l];
  try(0);
  return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

int x[15];
int n,m;
int a[15];
int sum =0;
int count;
void update(){
    if (sum == m){

        /*printf("Sol: ");
        for (int i =1; i<= n; i++){
            printf("%d ",x[i]);
        }
        printf("\n");*/
        count ++;
    }

}
void TRY(int i){
    //if (sum > m) return;
    for (int j = 1; j<= (m/a[i]) ; j++){
        x[i] = j;
        sum += a[i]*x[i] ;
        if (i == n) update();
        else if (sum <= m) TRY(i+1);
        sum -= a[i]*x[i];
    }
}
int main()
{

    scanf("%d",&n);
    scanf("%d",&m);
    for (int i =1; i<= n; i++){
        scanf("%d",&a[i]);

    }
    TRY(1);
    printf("%d",count);
    return 0;
}
