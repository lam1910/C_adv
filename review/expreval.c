#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 1000000007

int* number, * op;
int n, result;

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

void swap(int *a, int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

//(x * y) mod P
int multiMod(int x, int y, int P)
{
  if (x == 0 || y == 0)
    return 0;
  if (x == 1)
    return y % P;
  if (y == 1)
    return x % P;
  if (x > y)
    swap(&x, &y);
  int c = multiMod(x/2, y, P);
  c = addMod(c, c, P);
  if (x % 2 == 0)
    return c;
  else
    return addMod(c, y, P);
}

//stack
// A structure to represent a stack 
struct StackNode 
{ 
    int data; 
    struct StackNode* next; 
}; 
  
struct StackNode* newNode(int data) 
{ 
    struct StackNode* stackNode = 
              (struct StackNode*) malloc(sizeof(struct StackNode)); 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
} 
  
int isEmpty(struct StackNode *root) 
{ 
    return !root; 
} 
  
void push(struct StackNode** root, int data) 
{ 
    struct StackNode* stackNode = newNode(data); 
    stackNode->next = *root; 
    *root = stackNode; 
    //printf("%d pushed to stack\n", data); 
} 
  
int pop(struct StackNode** root) 
{ 
    if (isEmpty(*root)) 
        return INT_MIN; 
    struct StackNode* temp = *root; 
    *root = (*root)->next; 
    int popped = temp->data; 
    free(temp); 
  
    return popped; 
} 
  
int peek(struct StackNode* root) 
{ 
    if (isEmpty(root)) 
        return INT_MIN; 
    return root->data; 
} 


void init()
{
  int i, j;
  scanf("%d%*c", &n);
  number = (int *)malloc(n * sizeof(int));
  op = (int *)malloc((n - 1) * sizeof(int));
  for (i = 0; i < n; i ++)
    scanf("%d%*c", number + i);
  for (j = 0; j < n - 1; j ++)
    scanf("%d%*c", op + j);
}

void solve()
{
  int i, h;
  int tmp;
  struct StackNode* eval = NULL;
  push(&eval, *number);
  for (i = 0; i < n - 1; i ++)
    {
      if ((*(op + i)) == 0)
	{
	  tmp = 0 - number[i + 1];
	  push(&eval, tmp);
	}
      else if ((*(op + i)) == 1)
	{
	  push(&eval, number[i + 1]);
	}
      else
	{
	  h = pop(&eval);
	  tmp = multiMod(h, number[i + 1], N);
	  push(&eval, tmp);
	  result += tmp;
	}
    }
  result = 0;
  while (!isEmpty(eval))
    {
      h = pop(&eval);
      result = addMod(result, h, N);
    }
  printf("%d\n", result);
  free(eval);
}

int main()
{
  int i;
  init();
  solve();
  free(number);
  free(op);
  return 0;
}
