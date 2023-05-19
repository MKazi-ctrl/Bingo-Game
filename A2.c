#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

int checkint(char *S);
int verify(char *S);
void printCard(int c[25], int m[25]);
int rangecheck(int c[25]);
int checkCardDuplicates(int c[25]);
void mark(int c[25], int m[25], int number);
void checkwin(int m[25]);


int main(int argc, char *argv[]) {

 FILE *fp;
 if(argc != 3){
    fprintf(stderr,"Usage: %s seed cardFile\n",argv[0]);
    exit(1);
  }
 if ((fp = fopen(argv[2],"r")) == NULL) {
     fprintf(stderr,"%s is nonexistent or unreadable\n",argv[2]);
     exit(3);
  }

  fp = fopen(argv[2], "r");
  int card[25];
  int i = 0;

  while (i <= 25) {
    fscanf(fp,"%2d",&card[i]);
    i++;
  }


  if(!checkint(argv[1])) {
    fprintf(stderr,"Expected integer seed, but got %s\n",argv[1]);
    exit(2);
  }



  if(verify(argv[2]) != 25 || rangecheck(card) == 0 || checkCardDuplicates(card) == 0){
    fprintf(stderr, "%s has bad format\n",argv[2]);
    exit(4);
   }

  system("clear");
  list lst;
  char number[2];
  int marked[25];
  
  lst = init(76);

  int seed = atoi(argv[1]);
  srand(seed);
  char input[76];
  int random;

  printf("CallList: ");
  printCallList(lst);
  printf("\n");
  printCard(card, marked);
  printf("enter any non-enter key for Call (q to quit): ");
  fclose(fp);
  while(1){

    fgets(input,76,stdin);
    for (int i = 0; i < strlen(input)-1; i++){
        if (input[i] == 'q'){
                 exit(0);
            }
        random = (rand() % 75) + 1;
        while(check(random, lst) == 1){
          random = (rand() % 75) + 1;
        }
        if(check(random, lst) == 0){
          mark(card, marked, random);
          add(random, &lst);
        }
    }
    system("clear");
    printf("CallList: ");
    printCallList(lst);
    printf("\n");
    printCard(card, marked);
    checkwin(marked);
    printf("enter any non-enter key for Call (q to quit): ");
   }

}

int checkint(char *S) {
  while (*S){
    if (!isdigit(*S)) return 0;
    S++;
  }
  return 1;
}

int verify(char *S) {
  int i=0;
  int k=0;
  FILE *fp;
  fp = fopen (S, "r");
  while (fscanf(fp,"%d", &k) == 1) {
    i += 1;
  }
  return i;
}

void printCard(int c[25], int m[25]){
printf("L   I   N   U   X\n");
for(int i=0; i<25; i++){

  if (i % 5 == 0 & i != 0){
    if (c[i] <= 9 & c[i] >= 0){
      if(m[i] == 1){
        printf("\n0%dm ",c[i]);
      }
      else{
        printf("\n0%d  ",c[i]);
      }
    }
    else {
      if(m[i] == 1){
        printf("\n%dm ",c[i]);
      }
      else{
        printf("\n%d  ",c[i]);
      }
  }
 }

  else if (i == 0 & c[i] <= 9 & c[i] >= 0){
     if(m[i] == 1){
       printf("0%dm ",c[i]);
     }
     else{
       printf("0%d  ",c[i]);
     }
  }

 else {
  if (i == 12){
   printf("0%dm ",c[i]);
  }
  else{
    if(m[i] == 1){
     printf("%dm ", c[i]);
    }
    else{
      printf("%d  ", c[i]);
    }
  }
}
}
printf("\n");
}

int rangecheck(int c[25]){

for(int i=0; i<25; i++){

  if (i == 0 || i == 5 || i == 10 || i == 15 || i == 20){
    if(c[i] < 1 || c[i] > 15 ){
       return 0;
    }
  }

  if (i == 1 || i == 6 || i == 11 || i == 16 || i == 21){
    if(c[i] < 16 || c[i] > 30 ){
        return 0;
    }
  }

   if (i == 2 || i == 7 || i == 12 || i == 17 || i == 22){
      if(i != 12){
        if(c[i] < 31 || c[i] > 45 ){
          return 0;
        }
      }
      else{
        if(c[i] != 0){
          return 0;
        }
      }
  }

   if (i == 3 || i == 8 || i == 13 || i == 18 || i == 23){
    if(c[i] < 46 || c[i] > 60 ){
        return 0;
    }
  }

   if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24){
    if(c[i] < 61 || c[i] > 75 ){
        return 0;
    }
  }
}
return 1;

}

int checkCardDuplicates(int c[25]){

  for(int i=0; i<24; i++){

    for(int j = i + 1; j < 25; j++ ){

      if(c[i] == c[j]){
        return 0;
      }

    }
  }

  return 1;

}

void mark(int c[25], int m[25], int number){

    for(int i = 0; i < 25; i++){
        if(number == c[i]){
        m[i] = 1;
        }
        else{
          if(m[i] != 1){
              m[i] = 0;
          }
        }
    }
}

void checkwin(int m[25]){

  if (m[0] == 1 && m[5] == 1 && m[10] == 1 && m[15] == 1 && m[20] == 1){
    printf("WINNER\n");
    exit(0);
  }
  if (m[1] == 1 && m[6] == 1 && m[11] == 1 && m[16] == 1 && m[21] == 1){
    printf("WINNER\n");
    exit(0);
  }
  if (m[2] == 1 && m[7] == 1 && m[12] == 1 && m[17] == 1 && m[22] == 1){
     printf("WINNER\n");
     exit(0);
  }
  if (m[3] == 1 && m[8] == 1 && m[13] == 1 && m[18] == 1 && m[23] == 1){
    printf("WINNER\n");
    exit(0);
  }
  if (m[4] == 1 && m[9] == 1 && m[14] == 1 && m[19] == 1 && m[24] == 1){
    printf("WINNER\n");
    exit(0);
  }
  if (m[0] == 1 && m[1] == 1 && m[2] == 1 && m[3] == 1 && m[4] == 1){
     printf("WINNER\n");
     exit(0);
  }
  if (m[5] == 1 && m[6] == 1 && m[7] == 1 && m[8] == 1 && m[9] == 1){
    printf("WINNER\n");
    exit(0);
  }
  if (m[10] == 1 && m[11] == 1 && m[12] == 1 && m[13] == 1 && m[14] == 1){
    printf("WINNER\n");
    exit(0);
  }
  if (m[15] == 1 && m[16] == 1 && m[17] == 1 && m[18] == 1 && m[19] == 1){
    printf("WINNER\n");
    exit(0);
  }
  if (m[20] == 1 && m[21] == 1 && m[22] == 1 && m[23] == 1 && m[24] == 1){
    printf("WINNER\n");
    exit(0);
  }
  if (m[0] == 1 && m[4] == 1 && m[20] == 1 && m[24] == 1 ){
    printf("WINNER\n");
    exit(0);
  }

}
