#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(List );
List insertPos(List ,int ,int );
List deletePos(List ,int );
int locate(List , int );
List insertSorted(List ,int );
void display(List );
List resize(List );
void makeNULL(List );

int main (){

    List L = initialize(L);



}

List initialize(List L){

    L.elemPtr = malloc(sizeof(int) * LENGTH);
    L.max = LENGTH;
    L.count = 0;

    return L;
}

List insertPos(List L,int data,int pos){

    if(pos > L.count){
        return L;
    }

    if(L.count == L.max){
        L = resize(L);
    }

    for(int i = pos; i < L.count; i--){
        L.elemPtr[i] = L.elemPtr[i - 1];
    }

    if(L.)

}

// List deletePos(List ,int ){



// }

// int locate(List , int ){

// }

// List insertSorted(List ,int ){

// }

// void display(List ){

// }

// List resize(List ){

// }

// void makeNULL(List ){

// }
