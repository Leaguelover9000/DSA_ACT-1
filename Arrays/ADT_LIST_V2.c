#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr);
void insertPos(EPtr , int, int);
void deletePos(EPtr , int);
int locate(EPtr , int);
int retrieve(EPtr , int);
void insertSorted(EPtr ,int);
void display(EPtr);
void makeNULL(EPtr);

int main(){

    EPtr L = malloc(sizeof(Etype));
    initialize(L);

    insertPos(L,10,0);
    insertPos(L,20,1);
    insertPos(L,30,2);
    insertPos(L,40,3);
    insertPos(L,50,4);
    display(L);
    deletePos(L, 1);
    display(L);
    insertSorted(L, 8);
    display(L);
    int location = locate(L, 10);
    printf("Location is in index: %d\n", location);
    int re = retrieve(L, 1);
    printf("Element in this index is: %d\n", re);
    display(L);
    makeNULL(L);

    return 0;
}

void initialize(EPtr L){

    for(int i = 0; i < MAX; i++){
        L->elem[i] = 0;
    }

    L->count = 0;
}

void insertPos(EPtr L, int data, int pos){

    if(pos > L->count || L->count == MAX){
        return ;
    }

    for(int i = L->count; i > pos; i--){
        L->elem[i] = L->elem[i-1];
    }

    if(L->elem[pos] == 0){
        L->elem[pos] = data;
        L->count++;
    }else{
        L->elem[pos] = data;
    }
}

void deletePos(EPtr L, int pos){

    if(pos > L->count || L->count == MAX){
        return ;
    }

    for(int i = pos; i < L->count; i++){
        L->elem[i] = L->elem[i+1];
    }

    L->count--;

}

int locate(EPtr L, int data){

    for(int i = 0; i < L->count; i++){

        if(L->elem[i] == data){
            return i;
        }
    }

    return -1;
}

int retrieve(EPtr L, int pos){

    if(pos > L->count || L->count == MAX){
        return ;
    }

    for(int i = 0; i < L->count; i++){

        if(i == pos){
            return L->elem[i];
        }
    }

    return -1;
}

void insertSorted(EPtr L,int data){

    insertPos(L, data, L->count);

    if(L->count == MAX){
        return ;
    }

    for(int i = 0; i < L->count - 1; i++){
        for(int j = 0; j < L->count - 1; j++){
            if(L->elem[j] > L->elem[j + 1]){
                int temp = L->elem[j + 1];
                L->elem[j + 1] = L->elem[j];
                L->elem[j] = temp; 
            }
        }
    }    
}

void display(EPtr L){

    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }

    printf("\n");
}

void makeNULL(EPtr L){

    free(L);
}
