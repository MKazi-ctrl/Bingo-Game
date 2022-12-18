A2 :    A2.o list.o
        cc -o A2 A2.o list.o

A2.o :  A2.c list.h
        cc -c A2.c

list.o : list.c list.h
        cc -c list.c 

clean :
        rm A2 *.o
