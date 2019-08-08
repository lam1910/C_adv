#include <stdio.h>
#include <stdlib.h>

#define filename "graph.txt"
#define MAX 1000

//adjacent list
int z[MAX];

//adjacent matrix;
int A[MAX][MAX];

//number of element
int n;

//indicator of whether visited or not
char colour[MAX];

int result;


/*//get value from matrix at row i, col j
int getValue(int* matrix, int noCols, int i, int j)
{
  return matrix[i + i * (noCols - 1) + j];
}

//set value for matrix at row i,  col j
void setValue(int** mtrPtr, int noCol, int i, int j, int val)
{
  *mtxPtr[i + i * (noCols - 1) + j] = val;
  }*/

//built a graph through adjacent matrix 
void input()
{
  FILE* fptr;
  fptr = fopen(filename, "r+");
  int m, i;
  fscanf(fptr, "%d %d\n", &n, &m);
  for (i = 0; i < n; i ++)
    z[i] = 0;
  for (i = 0; i < m; i ++)
    {
      int u, v;
      fscanf(fptr, "%d %d\n", &u, &v);
      z[u] ++;
      A[u - 1][z[u] - 1] = v;
      z[v] ++;
      A[v - 1][z[v] - 1] = u;
    }
  fclose(fptr);
}

//utility function to see the graph
void printGraph()
{
  int v;
  for (v = 1; v <= n; v ++)
    {
      printf("A[%d] = ", v);
      int i;
      for (i = 0; i < z[v]; i ++)
	{
	  printf("%d ", A[v - 1][i]);
	}
      printf("\n");
    }
}

//init colour of node
void init()
{
  int i;
  for (i = 0; i < n; i ++)
    colour[i] = 'w';
}

//depth-first search
void DFS(int u)
{
  colour[u] = 'g';
  int i;
  for (i = 0; i < z[u]; i ++)
    {
      int v = A[u - 1][i];
      if (colour[v] == 'w')
	DFS(v);
    }
}

int main()
{
  input();
  init();
  //printGraph();
  result = 0;
  int v;
  for (v = 1; v <= n; v ++)
    {
      if (colour[v] == 'w')
	{
	  result ++;
	  DFS(v);
	}
    }
  printf("%d\n", result);
  return 0;
}
