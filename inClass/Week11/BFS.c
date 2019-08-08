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

//indicator of whether visited or not (w means not, g means it's visited, b means done)
char colour[MAX];

//queue
// A linked list (LL) node to store a queue entry 
struct QNode 
{ 
    int key; 
    struct QNode* next; 
}; 
  
// The queue, front stores the front node of LL and rear stores ths 
// last node of LL 
struct Queue 
{ 
    struct QNode* front, * rear; 
}; 
  
// A utility function to create a new linked list node. 
struct QNode* newNode(int k) 
{ 
    struct QNode* temp = (struct QNode* )malloc(sizeof(struct QNode)); 
    temp->key = k; 
    temp->next = NULL; 
    return temp;  
} 
  
// A utility function to create an empty queue 
struct Queue* createQueue() 
{ 
    struct Queue* q = (struct Queue* )malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
}

int isEmpty(struct Queue* q)
{
  return ((q->front == NULL) && (q->rear == NULL));
}
  
// The function to add a key k to q 
void enQueue(struct Queue* q, int k) 
{ 
    // Create a new LL node 
    struct QNode* temp = newNode(k); 
  
    // If queue is empty, then new node is front and rear both 
    if (q->rear == NULL) 
    { 
       q->front = q->rear = temp; 
       return; 
    } 
  
    // Add the new node at the end of queue and change rear 
    q->rear->next = temp; 
    q->rear = temp; 
} 
  
// Function to remove a key from given queue q 
struct QNode* deQueue(struct Queue* q) 
{ 
    // If queue is empty, return NULL. 
    if (q->front == NULL) 
       return NULL; 
  
    // Store previous front and move front one node ahead 
    struct QNode* temp = q->front; 
    q->front = q->front->next; 
  
    // If front becomes NULL, then change rear also as NULL 
    if (q->front == NULL) 
       q->rear = NULL; 
    return temp; 
} 
  

//check whether a element v is in the row x
int in(int x, int v)
{
  int l;
  for (l = 0; l < z[x]; l ++)
    {
      if (A[x][l] == v)
	return 1;
    }
  return 0;
}

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

//init colour of node
void init()
{
  int i;
  for (i = 0; i < n; i ++)
    colour[i] = 'w';
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

//breadth-first search shortest path from s to v
int BFS(int s, int v)
{
  //queue for BFS
  struct Queue* q = createQueue();
  colour[s] = 'g';
  int d = 0;
  int n, i;
  enQueue(q, s);
  while (!isEmpty(q))
    {
      struct QNode* tmp = deQueue(q);
      int u = tmp->key;
      if (in(u - 1, v))
	return d;
      d ++;
      for (i = 0; i < z[u]; i ++)
	{
	  n = A[u - 1][i];
	  if (colour[n] = 'w')
	    {
	      colour[n] = 'g';
	      enQueue(q, n);
	    }
	}
      colour[u] = 'b';
    }
}

int main()
{
  input();
  init();
  printGraph();
  int u = BFS(1, 3);
  printf("%d\n", u);
  return 0;
}
