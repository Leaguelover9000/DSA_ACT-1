#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List* initialize();
void empty(List *);
void insertFirst(List* , int);
void insertLast(List* , int);
void insertPos(List * , int, int);
void deleteStart(List *);
void deleteLast(List *);
void deletePos(List *, int);
int retrieve(List *, int);
int locate(List *, int);
void display(List *);

int main(){

    List *L = initialize();

    insertFirst(L, 10);
    display(L);
    insertFirst(L, 20);
    display(L);
    insertFirst(L, 30);
    display(L);
    insertFirst(L, 40);
    display(L);
    insertLast(L, 20);
    display(L);
    insertPos(L, 50, 3);
    display(L);
    deleteStart(L);
    display(L);
    deleteLast(L);
    display(L);
    deletePos(L, 1);
    display(L);
    int getData = retrieve(L, 2);
    printf("The data is: %d\n", getData);
    int getIndex = locate(L, 10);
    printf("The index is: %d\n", getIndex);
    empty(L);

    return 0;
}

List* initialize(){

    List *temp = malloc(sizeof(List));

    if(temp == NULL){
        printf("Allocation failed\n");
        return NULL;
    }

    temp->head = NULL;
    temp->count = 0;

    return temp;
}

void empty(List *L){

    Node *current = L->head;

    while(current != NULL){
        Node *delete = current;
        current = current->next;
        free(delete);
    }

    L->head = NULL;
    L->count = 0;
}

void insertFirst(List* L, int data){

    Node *temp = malloc(sizeof(Node));

    if(temp == NULL){
        printf("Allocation failed\n");
    }

    temp->data = data;
    temp->next = L->head;

    L->head = temp;
    L->count++;
}

void insertLast(List* L, int data){

    Node *temp = malloc(sizeof(Node));

    if(temp == NULL){
        printf("Allocation failed\n");
    }

    temp->data = data;
    temp->next = NULL;

    if(L->head == NULL){
        insertFirst(L, data);
        return ;
    }

    Node *current = L->head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = temp;
    L->count ++;
}

void insertPos(List *L, int data, int index){

    if(index > L->count){
        return ;
    }

    if(index == 0){
        insertFirst(L, data);
        return ;
    }

    if(index == L->count){
        insertLast(L, data);
        return ;
    }

    Node *temp = malloc(sizeof(Node));
    temp->data = data;

    Node **current = &L->head;

    for(int i = 0; i != index - 1; i++, current = &(*current)->next){}

    temp->next = (*current)->next;
    (*current)->next = temp;

    L->count++;
}

void deleteStart(List *L){

    Node *current = L->head;
    L->head = L->head->next;
    free(current);
    L->count--;
}

void deleteLast(List *L){
    
    if(L->head->next == NULL){
        deleteStart(L);
        return ;
    }

    Node **current = &L->head;

    for(int i = 0; i != L->count - 2; i++, current = &(*current)->next){}

    free((*current)->next);
    (*current)->next = NULL;
    L->count--;
}

void deletePos(List * L, int index){

    if(index == 0){
        deleteStart(L);
        return ;
    }

    Node **current = &L->head;

    for(int i = 0; i != index-1; i++, current = &(*current)->next){}

    Node *temp = (*current)->next;
    (*current)->next = temp->next;
    free(temp);

    L->count--;
}

int retrieve(List *L, int index){

    if(index > L->count){
        return -1;
    }

    if(index == 0){
        return L->head->data;
    }

    Node *current = L->head;

    int i = 0;
    for(; i != index - 1; current = current->next, i++){}

    return i == index - 1 ? current->data : -1;
}

int locate(List *L, int data){

    if(L->head == NULL){
        return -1;
    }

    Node *current = L->head;
    int index = 0;
    for(; current->data != data; current = current->next, index++){}

    return current->data == data ? index : -1;
}

void display(List *L){

    List trav = *L;

    for(; trav.head != NULL; trav.head = trav.head->next){
        printf("%d ", trav.head->data);
        if(trav.head->next != NULL){
            printf("-> ");
        }
    }

    printf("\n");
}
