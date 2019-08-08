typedef int elmtypeL;
typedef struct node node;
typedef struct node
{
  elmtypeL id;
  node* toFront;
  node* toRear;
}node;

typedef struct queue
{
  node* Front;
  node* Rear;
}queueType;


void initQ(queueType* p)
{
  p->Front = NULL;
  p->Rear = NULL;
}

node* makeNewNode(elmtypeL id)
{
  node* new;
  new = (node* )malloc(sizeof(node));
  new->id = id;
  new->toFront = NULL;
  new->toRear = NULL;
  return new;
}

int isEmpty(queueType* p)
{
  return ((p->Front == NULL) && (p->Rear == NULL));
}

void enQueue(queueType* p, elmtypeL id)
{
  if (isEmpty(p))
    {
      node* tmp = makeNewNode(id);
      p->Front = tmp;
      p->Rear = NULL;
    }
  else if (p->Rear == NULL)
    {
      node* tmp = makeNewNode(id);
      p->Front->toRear = tmp;
      tmp->toFront = p->Front;
      p->Rear = p->Front->toRear;
    }
  else
    {
      node* append = makeNewNode(id);
      p->Rear->toRear = append;
      append->toFront = p->Rear;
      p->Rear = p->Rear->toRear;
    }
}

elmtypeL deQueue(queueType* p)
{
  if (isEmpty(p))
    {
      printf("Queue is empty.\n");
    }
  else
    {
      node* takeout = p->Front;
      p->Front = p->Front->toRear;
      p->Front->toFront = NULL;
      return takeout->id;
    }
}
