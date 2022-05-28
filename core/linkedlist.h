#ifndef ____LINKEDLIST___H___
#define ____LINKEDLIST___H___

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_OF(x) (sizeof(x) / sizeof(x[0]))
#define MAXSIZE 200

typedef struct node node;

struct node *head;
struct node *current;

void printList();

void insertFirst(int key, pid_t pid, char args[MAXSIZE]);

bool isEmpty();

int length();

#endif