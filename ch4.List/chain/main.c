#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode *listPointer; // 포인터 타입을 정의.
typedef struct listNode{
    int data;
    listPointer link;
} listNode;

//2개의 노드를 가진 연결리스트의 생성
listPointer create2(){
    listPointer first, second;
    first = malloc(sizeof(*first));
    second = malloc(sizeof(*second));
    second->link = NULL;
    second->data = 20;

    first->link = second;
    first->data = 10;
    return first;
}

void insert(listPointer *first, listPointer x){
    listPointer temp;
    temp = malloc(sizeof(*temp));
    temp -> data = 50;
    if(*first){
        temp->link = x->link;
        x->link = temp;
    } else {
        temp->link = NULL;
        *first = temp;
    }
}

void delete(listPointer *first, listPointer trail, listPointer x){
    if(trail){
        trail->link = x -> link;
    } else {
        *first = (*first)->link;
    }
    free(x);
}

void printList(listPointer first){
    printf("The list contains: ");
    for(;first;first = first->link){
        printf("%4d", first->data);
    }
    printf("\n");
}

int main() {
    listPointer first = create2();
    listPointer second = malloc(sizeof(*second));
    second->data = 200;
    insert(&first, first);
    printList(first);


    return 0;
}