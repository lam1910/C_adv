#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int n, x, y;
int maze[MAX][MAX];
int visited[MAX][MAX];

int dX[] = {1, -1, 0,  0};
int dY[] = {0,  0, 1, -1};

void init()
{
  int i, j;
  scanf("%d %d %d\n", &n, &x, &y);
  for (i = 0; i < MAX; i ++)
    for (j = 0; j < MAX; j ++)
      {
	maze[i][j] = -1;
	visited[i][j] = 1;
      }
  for (i = 1; i <= n; i ++)
    for (j = 1; j <= n; j ++)
      {
	scanf("%d%*c", &maze[i][j]);
	visited[i][j] = 0;
      }
  visited[x][y] = 1;
}

//queue
// A linked list (LL) node to store a queue entry 
struct QNode 
{ 
  int x;
  int y;
  int d;
  struct QNode* next; 
}; 
  
// The queue, front stores the front node of LL and rear stores ths 
// last node of LL 
struct Queue 
{ 
  struct QNode* front, * rear; 
}; 
  
// A utility function to create a new linked list node. 
struct QNode* newNode(int x, int y, int d) 
{ 
  struct QNode* temp = (struct QNode* )malloc(sizeof(struct QNode)); 
  temp->x = x;
  temp->y = y;
  temp->d = d;
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

// The function to add a x, y to q 
void enQueue(struct Queue* q, int x, int y, int d) 
{ 
  // Create a new LL node 
  struct QNode* temp = newNode(x, y, d); 
  
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

int check(int x, int y)
{
  if (maze[x][y] == -1 || maze[x][y] == 1)
    return 0;
  return 1;
}

void solve()
{
  int d = 0;
  struct Queue* Q;
  enQueue(Q, x, y, d);
  while (!isEmpty(Q))
    {
      struct QNode* tmp = deQueue(Q);
      int i;
      for (i = 0; i < 4; i ++)
	{
	  int x1 = tmp->x + dX[i];
	  int y1 = tmp->y + dY[i];
	  int d1 = d + 1;
	  d ++;
	  if (maze[x1][y1] == -1)
	    {
	      printf("%d\n", d1);
	      return;
	    }
	  if (check(x1, y1))
	    {
	      enQueue(Q, x1, y1, d1);
	      visited[x1][y1] = 1;
	    }
	}
    }
}
int main()
{
  init();
  solve();
}
