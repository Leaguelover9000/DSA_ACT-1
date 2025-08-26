#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List , int, int);
List deletePos(List , int);
int locate(List , int);
List insertSorted(List ,int);
void display(List );

int main(){

    List L = initialize(L);

    L = insertPos(L,10,2);
    display(L);
    L = deletePos(L, 1);
    display(L);
    L = insertSorted(L, 8);
    display(L);
    int location = locate(L, 10);
    printf("Location is in index: %d\n", location);
    display(L);

    return 0;
}

List initialize(List L){

    L.count = 0;

    for(int i = 0; i < 5; i++){
        L.elem[i] = i + 1;
        L.count++;
    }

    return L;
}

List insertPos(List L, int data, int pos){

    if(pos > L.count || L.count == MAX){
        return L;
    }

    for(int i = L.count; i > pos; i--){
        L.elem[i] = L.elem[i-1];
    }

    L.elem[pos] = data;
    L.count++;

    return L;
}

List deletePos(List L, int pos){

    if(pos > L.count || L.count == MAX){
        return L;
    }

    for(int i = pos; i < L.count; i++){
        L.elem[i] = L.elem[i+1];
    }

    L.count--;

    return L;
}

int locate(List L, int data){

    for(int i = 0; i < L.count; i++){

        if(L.elem[i] == data){
            return i;
        }
    }

    return 0;
}

List insertSorted(List L,int data){

    L = insertPos(L, data, L.count);

    if(L.count == MAX){
        return L;
    }

    for(int i = 0; i < L.count; i++){
        for(int j = 0; j < L.count; j++){
            if(L.elem[j] > L.elem[j + 1]){
                int temp = L.elem[j + 1];
                L.elem[j + 1] = L.elem[j];
                L.elem[j] = temp; 
            }
        }
    }    

    return L;
}

void display(List L){

    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }

    printf("\n");
}
