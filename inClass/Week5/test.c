
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 2000
typedef struct Node{
    int id;
    struct Node* next;
    struct Node* prev;
}TNode;

typedef struct Route{
    struct Node* start;
    struct Node* end;
    int distance;
}TRoute;
int c[MAX][MAX];
int n;

//best  result
int opt;

int distance(int id1, int id2){
    return c[id1][id2];
}

void genData(char* filename, int n){
    FILE* f=fopen(filename,"w");
    srand(time(NULL));
    fprintf(f,"%d\n",n);
    int i,j;
    for(i = 0; i <= n; i++)
        for(j = 0; j <= n; j++)
            c[i][j] = 0;
    int b[100000];
    for(i = 0; i < MAX; i++) b[i] = 0;
    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++){
            int x;
            do{
                x = rand()%100000;
            }while(b[x] == 1);
            b[x] = 1;
            fprintf(f,"%d ",x);
            printf("%d/%d\n",i,j);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}
void updateDistance(TRoute* r){
  int sum;
  TNode* tmp;
  for(tmp = r->start; tmp != r->end; tmp = tmp->next)
    {
      sum += distance(tmp->id, tmp->next->id);
    }
  sum += distance(r->end->id, r->start->id);
  r->distance = sum;
}

//reverse list
void reverse(TNode **head_ref) 
{ 
     TNode *temp = NULL;   
     TNode *current = *head_ref; 
       
     // swap next and prev for all nodes of doubly linked list
     while (current !=  NULL) 
     { 
       temp = current->prev; 
       current->prev = current->next; 
       current->next = temp;               
       current = current->prev; 
     }       
       
     // Before changing head, check for the cases like empty list and list with only one node
     if(temp != NULL ) 
        *head_ref = temp->prev; 
}

TRoute* twoOpt(TRoute* r, TNode* x, TNode* y){
    // remove (x, next[x])
    // remove (y, next[y])
    // add (x, y)
    // add (next[x], next[y])
    // reverse the route from y to x->next
    // TODO
  
  TNode* tmp1, * tmp2;
  tmp1 = x->next;
  tmp2 = y->next;
  x->next = y;
  tmp1->prev = NULL;
  y->next = NULL;
  tmp2->prev = NULL;
  reverse(&tmp1);
  y->prev = x;
  tmp2->prev = tmp1;
  tmp1->next = tmp2;
  return r;
}
  
  
  
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the Doubly Linked List */
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = 
            (struct Node*) malloc(sizeof(struct Node)); 
   
    /* put in the data  */
    new_node->id  = new_data; 
      
    /* since we are adding at the begining,  
      prev is always NULL */
    new_node->prev = NULL; 
   
    /* link the old list off the new node */
    new_node->next = (*head_ref);     
  
    /* change prev of head node to new node */
    if((*head_ref) !=  NULL) 
      (*head_ref)->prev = new_node ;     
   
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  
/* Function to print nodes in a given doubly linked list  
   This function is same as printList() of singly linked lsit */
void printList(struct Node *node) 
{ 
  while(node!=NULL) 
  { 
   printf("%d ", node->id); 
   node = node->next; 
  } 
}  
  
/* Drier program to test above functions*/
int main() 
{ 
  /* Start with the empty list */
  struct Node* head = NULL; 
   
  /* Let us create a sorted linked list to test the functions 
   Created linked list will be 10->8->11->7->4->2 */
  push(&head, 2);
  push(&head, 4);
  push(&head, 7);
  push(&head, 11);
  push(&head, 8); 
  push(&head, 10); 
   
  printf("\n Original Linked list "); 
  printList(head); 

  
  /* Reverse doubly linked list */
  twoOpt(&tmp1); 
   
  printf("\n Reversed Linked list "); 
  printList(head);            
   
  getchar(); 
} 
