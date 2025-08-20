#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef struct{
    int elem[size];
    int count;
}List;

List initialize(List);
List insertPos(List , int, int);
List deletePos(List, int);
int locate(List, int);
List insertSorted(List , int);
void display(List);

int main(){

    List Temp;
    List L = initialize(Temp);

    L = insertPos(L, 20, 3);
    display(L);
    L = deletePos(L, 3);
    display(L);
    int location = locate(L, 3);
    display(L);
    L = insertSorted(L, 4);
    display(L);

    return 0;
}

List initialize(List L){

    L.count = 0;

    for(int i = 0; i < size; i++){
        L.elem[i] = -1;
    }

    return L;
}

List insertPos(List L, int data, int pos){

    if(L.elem[pos-1] != -1){
        L.elem[pos-1] = data;
        L.count++;
    }else{
        L.elem[pos-1] = data;
    }

    return L;
}

List deletePos(List L, int pos){

    L.elem[pos-1] = -1;
    L.count--;

    return L;
}

int locate(List L, int data){

    for(int i = 0; i < L.count + 1; i++){
        if(L.elem[i] == data){
            return i+1;
        }
    }

    return 0;
}

List insertSorted(List L, int data){

    for(int i = 0; i < L.count+1; i++){
        if(L.elem[i] > L.elem{})
    }

    
}

void display(List L){

    for(int i = 0; i < size; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");

}
