#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define filename "graph.txt"
int n; //n: number of nodes
//list of numbers of next nodes;
int z[MAX];

//list of next nodes
int A[MAX][MAX];

//list pf cost
int d[MAX][MAX];

int s, t; //begin and end
void init()
{
  int i, j;
  for (i = 0; i < MAX; i ++)
    {
      z[i] = 0;
      for (j = 0; j < MAX; j ++)
	d[i][j] = 0;
    }
}

void input()
{
  int m, i;
  FILE* fptr;
  fptr = fopen(filename, "r+");
  fscanf(fptr, "%d %d\n", &n, &m);
  for (i = 0; i < m; i ++)
    {
      int u, v, k;
      fscanf(fptr, "%d %d %d\n", &u, &v, &k);
      z[u] ++;
      A[u - 1][z[u] - 1] = v;
      d[u - 1][v - 1] = k;
    }
  fscanf(fptr, "%d %d", &s, &t);
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
	  printf("%d-%d ", A[v - 1][i], d[v - 1][A[v - 1][i] - 1]);
	}
      printf("\n");
    }
}

int minDistance(int dist[], int sptSet[]) 
{ 
   // Initialize min value 
   int min = 10000000, min_index; 
   
   for (int v = 0; v < MAX; v++) 
     if (sptSet[v] == 0 && dist[v] <= min) 
         min = dist[v], min_index = v + 1; 
   
   return min_index; 
} 

//dijkstra
void minPath(int graph[MAX][MAX], int src, int desc) 
{ 
     int dist[MAX];     // The output array.  dist[i] will hold the shortest 
                      // distance from src to i 
   
     int sptSet[MAX]; // sptSet[i] will be true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
   
     // Initialize all distances as INFINITE and stpSet[] as false 
     for (int i = 0; i < MAX; i++) 
        dist[i] = 10000000, sptSet[i] = -1; 
   
     // Distance of source vertex from itself is always 0 
     dist[src - 1] = 0; 
   
     // Find shortest path for all vertices 
     for (int count = 0; count < MAX-1; count++) 
     { 
       // Pick the minimum distance vertex from the set of vertices not 
       // yet processed. u is always equal to src in the first iteration. 
       int u = minDistance(dist, sptSet); 
   
       // Mark the picked vertex as processed 
       sptSet[u - 1] = 1; 
   
       // Update dist value of the adjacent vertices of the picked vertex. 
       for (int v = 1; v <= MAX; v++) 
   
         // Update dist[v] only if is not in sptSet, there is an edge from  
         // u to v, and total weight of path from src to  v through u is  
         // smaller than current value of dist[v] 
         if (sptSet[v - 1] != 1 && graph[u - 1][v - 1] && dist[u - 1] != 10000000  
                                       && dist[u - 1]+graph[u - 1][v - 1] < dist[v - 1]) 
            dist[v -1] = dist[u - 1] + graph[u - 1][v - 1]; 
     } 
  printf("%d\n", dist[desc - 1]);
}

int main()
{
  init();
  input();
  //printGraph();
  minPath(d, 1, 6);
  return 0;
}
