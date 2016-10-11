#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list(struct node *n) {
  printf("List: { ");
  while(n->next != NULL) {
    printf("%d ", n->i);
    n = n->next;
  }
  printf("%d }\n", n->i);
}

struct node * insert_front(struct node *n , int new) {
  struct node *temp = malloc(sizeof(struct node));
  temp->i = new;
  temp->next = n;
  return temp;
}


struct node * free_list(struct node *n) {
  if(n->next != NULL) {
    free_list(n->next);
  }
  free(n);
  printf("List running free!\n");
  return n;
}

int main() {

  struct node *rosh;
  rosh = (struct node *)malloc(sizeof(struct node));
  printf("Initial node: rosh\nSize of rosh: %lu\n", sizeof(rosh));
  
  (*rosh).i = 1;
  rosh->next = NULL;
  //printf("Value of rosh: %d\n", rosh->i);

  printf("\nFirst List\n");
  print_list(rosh);

  rosh = insert_front(rosh, 2);
  printf("\nSecond List(Two Nodes)\n");
  print_list(rosh);

  free_list(rosh);
  return 0;
}

