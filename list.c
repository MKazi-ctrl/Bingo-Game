#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void add(int item, list *lis){
    *(lis->lastElem) = item;
    lis->size++;
    lis->lastElem++;
}
int check (int item, list lis){
    for(int i = 0; i < lis.size; i++){
        if(item == lis.callList[i]){
            return 1;
        }
    }
    return 0;
}

void print(list lis){
    for(int i = 0; i < lis.size; i++){
        printf("%d ", lis.callList[i]);
    }
    printf("\n");
}

void printCallList(list lis){
    for(int i = 0; i < lis.size; i++){
        int item = lis.callList[i];
        if(item < 10){
            printf("L0%d ", item);
        }
        else if(item < 16){
            printf("L%d ", item);
        }
        else if(item < 31){
            printf("I%d ", item);
        }
        else if(item < 46){
            printf("N%d ", item);
        }
        else if(item < 61){
            printf("U%d ", item);
        }
        else if(item < 76){
            printf("X%d ", item);
        }
    }
    printf("\n");
}

list init(int sizeOfList){
    list lst;
    lst.callList = (int *) malloc(sizeOfList * sizeof(int));
    lst.size = 0;
    lst.lastElem = lst.callList;
    return lst;
}
