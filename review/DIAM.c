#include <stdio.h>
#include <stdlib.h>

#define MAX 200

int n, m;

//adjacent list
int z[MAX];

//adjacent matrix;
int A[MAX][MAX];

//indicator of whether visited or not
char colour[MAX];

void init()
{
  int i, j, u, v;
  for (i = 0; i < MAX; i++)
    for(j = 0; j < MAX; j ++)
      A[i][j] = 0;
  for (i = 0; i < MAX; i ++)
    colour[i] = 'w';
  scanf("%d%*c%d\n", &n, &m);
  for (i = 0; i < m; i ++)
    {
      scanf("%d%*c%d%*c", &u, &v);
      z[u] ++;
      A[u - 1][z[u] - 1] = v;
      z[v] ++;
      A[v - 1][z[v] - 1] = u;
    }
}

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

//breadth-first search shortest path from s to v
int BFS(int s, int v)
{
  //queue for BFS
  struct Queue* q = createQueue();
  colour[s - 1] = 'g';
  int d = 0;
  int n, i;
  enQueue(q, s);
  while (!isEmpty(q))
    {
      struct QNode* tmp = deQueue(q);
      int u = tmp->key;
      if (in(u - 1, v - 1))
	return d;
      d ++;
      for (i = 0; i < z[u]; i ++)
	{
	  n = A[u - 1][i];
	  if (colour[n - 1] = 'w')
	    {
	      colour[n - 1] = 'g';
	      enQueue(q, n);
	    }
	}
      colour[u - 1] = 'b';
    }
}

void solve()
{
  int i, j, max = -1;
  int distance[n][n];
  for (i = 0; i < n; i ++)
    distance[i][i] = 0;
  for (i = 1; i <= n; i ++)
    for (j = 1; j <= n; j ++)
      distance[i - 1][j - 1] = BFS(i, j);
  for (i = 0; i < n; i ++)
    {
      for (j = 0; j < n; j ++)
	{
	  if (i == j || max >= distance[i][j])
	    continue;
	  else
	    max = distance[i][j];
	}
    }
  printf("%d\n", max);
}


int main()
{
  init();
  solve();
}
