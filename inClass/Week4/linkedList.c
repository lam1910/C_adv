#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define fileName "route.inp"

//total load
int totalLoad = 0;
typedef struct node node;

//struct for node
typedef struct node
{
  int id;
  double distance;
  int load;
  node* prev;
  node* next;
}node;

//create a new node
node* makeNewNode(int ID, double dis, int load)
{
  node* new;
  new = (node* )malloc(sizeof(node));
  new->id = ID;
  new->distance = dis;
  new->load = load;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

node* root, *tail, *cur;

node* root1 = NULL, *tail1 = NULL, *cur1 = NULL;

//create empty list
void makeNull()
{
  root = NULL;
  tail = NULL;
  cur = NULL;
}

//insert after current position
void insertAfter(int ID, double dis, int load)
{
  node* append = makeNewNode(ID, dis, load);
  if (root == NULL)
    {
      root = append;
      cur = root;
    }
  else if ((cur == tail) || (cur->next == NULL))
    {
      append->prev = cur;
      cur->next = append;
      cur = cur->next;
      tail = append->next;
    }
  else
    {
      append->next = cur->next;
      append->prev = cur;
      cur->next = append;
      cur = cur->next;
      cur->next->prev = append;
    }
}

//clear content
void freeLinked()
{
  node* to_free = root;
  while (to_free != NULL)
    {
      root = root->next;
      free(to_free);
      to_free = root;
    }
}

//read from input file
void readInput()
{
  FILE* file;
  file = fopen(fileName, "r+");
  if (file == NULL)
    {
      printf("Cannot open %s.\nExit!", fileName);
      exit(1);
    }
  else
    {
      makeNull();
      int n, i, pos, x, y, l, pos0, x0, y0;
      fscanf(file, "%d%*c%d%*c%d%*c%d%*c", &n, &pos0, &x0, &y0);
      insertAfter(pos0, sqrt(x0*x0 + y0*y0), 0);
      for (i = 0; i < n; i ++)
	{
	  fscanf(file, "%d%*c%d%*c%d%*c%d%*c", &pos, &x, &y, &l);
	  insertAfter(pos, sqrt(x*x +y*y), l);
	  totalLoad += l;
	}
      insertAfter(pos0, sqrt(x0*x0 + y0*y0), 0);
    }
  fclose(file);
}

//update load
void update(node* r)
{
  node* tmp;
  int temp;
  for (tmp = r; tmp->next != NULL; tmp = tmp->next)
    {
      temp = tmp->load;
      tmp->load = totalLoad - temp;
      totalLoad -= temp;
    }
}

//print a single node
void printNode(node* now)
{
  if (now == NULL)
    {
      printf("Do not have this node.\n");
      return;
    }
  int id = now->id;
  double distance = now->distance;
  int load = now->load;
  printf("%d\t%lf\t%d\n", id, distance, load);
  printf("to\n");
}

//show all node
void traversingList(node* r)
{
  node* tmp;
  for (tmp = r; tmp != NULL; tmp = tmp->next)
    printNode(tmp);
  printf("\n\tEnd of list\n");
}

//split list at position i, j (assume i, j in the length of list)
void split(int i, int j)
{
  int tmp = 0;
  node* temp;
  root1 = makeNewNode(0, 0, 0);
  cur1 = root1;
  while (
}

int main()
{
  int choice;
  int start, end;
  do
    {
      printf("____________________\n");
      printf("Menu:\n");
      printf("\t1: Make a route.\n");
      printf("\t2: Split into 2 routes.\n");
      printf("\t3: End.\n");
      printf("Your choice: ");
      scanf("%d", &choice);
      switch(choice)
	{
	case 1:
	  readInput();
	  update(root);
	  traversingList(root);
	  break;
	case 2:
	  printf("Starting point i and finishing point j of splited route (1 < i < j < 10): ");
	  scanf("%d%*c%d", &start, &end);
	  do
	    {
	      printf("Wrong input!\nTry again!\n");
	      printf("Starting point i and finishing point j of splited route (1 < i < j < 10): ");
	      scanf("%d%*c%d", &start, &end);
	    }while((start >= end) || ((start < 0) || (start > 10)) || ((end < 0) || (end > 10)));
	  break;
	case 3:
	  break;
	default:
	  printf("Wrong choice!\n");
	}
    }while (choice != 3);
  freeLinked();
  return 0;
}

  
