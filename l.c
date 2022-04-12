#include <stdio.h>

typedef struct ADTList {
    int *callList;
    int *lastElem;
    int size;
} list;

void add (int item, list *lis);
int check (int item, list lis);
void print(list lis);
void printCallList(list lis);
list init(int sizeOfList);
