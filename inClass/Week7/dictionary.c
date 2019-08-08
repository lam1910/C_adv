#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

int rs;


void addDict(char* key)
{
  int h = hash(key);
  bst[h] = addBST(bst[h], key);
}

void run()
{
  rs = 0;
  while(1)
    {
      char* s = (char*)malloc(1000* sizeof(char));
      scanf("%s", s);
      if (strcmp(s, "-1") == 0)
	break;
      int c = 0;
      BSTtype nod = search(s);
      if (nod != NULL)
	c = nod->count;
      if (c + 1 > rs)
	rs = c + 1;
    }
  printf("%d", rs);
}

int main()
{
  
}
