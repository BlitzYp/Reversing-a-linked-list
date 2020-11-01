#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* next;
};

void reverse(struct Node* head) 
{
  struct Node* current, *next, *prev;
  current = head;
  prev = NULL;
  while (current != NULL) 
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}

struct Node* insert(struct Node* head, int value) 
{
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->value = value;
  newNode->next = head;
  return newNode;  
}

void print(struct Node* head)
{
  struct Node* current = head;
  while(current != NULL)
  {
    printf("%d\n", current->value);
    current = current->next;
  }
}

int main(void) {
  struct Node* head = insert(NULL, 6);
  head = insert(head, 8);  
  head = insert(head, 9);
  reverse(head);
  print(head);
  return 0;
}
