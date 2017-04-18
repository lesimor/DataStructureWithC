#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1


// 스택에 들어갈 element의 타입 정의
typedef struct{
    int key;
} element;

// 현재 할당된 용량
int capacity = 1;

// 스택 포인터 선언
// 스택을 동적으로 사용
element *stack;


// top위치
int top = -1;

// 스택 관련 함수
// 스택이 비어있는지 확인.
int isEmpty(){
    return top <= -1 ? TRUE : FALSE;
}

// 스택이 가득 차있는지 확인 후 차있으면 두배 확장
void isFullCheck(){
    if (top >= capacity - 1){
        realloc(stack, 2 * sizeof(element));
        capacity *= 2;
        printf("스택이 두배 늘어났습니다.(용량: %d)\n", capacity);
    }
}

// 스택에 element를 push
void push(int num){
    isFullCheck();
    printf("%d 삽입!!\n", num);
    stack[++top].key = num;
}

// 스택으로부터 element를 pop하고 해당 요소의 key를 반환
int pop(){
    if(isEmpty()){
        printf("스택이 비어있어서 pop할 수 없습니다.");
        return 0;
    } else {
        printf("pop!!!%d이 튀어나왔다.\n", stack[top].key);
        return stack[top--].key;
    }

}

// 스택의 상태를 보여줌
void printStack(){
    if(isEmpty()){
        printf("스택이 비어있습니다.\n");
    } else {
        int i;
        printf("-----stack(MaxSize: %d)------\n", capacity);
        for(i = top ; i >= 0 ; i--){
            printf("|| %d ||\n", stack[i].key);
        }
        printf("----------------\n");
    }

}

int main() {
    stack = (element*)malloc(sizeof(element));
    printStack();
    push(3);
    printStack();
    push(2);
    printStack();
    push(5);
    printStack();
    push(2);
    printStack();
    push(2);
    printStack();
    push(2);
    printStack();
    push(2);


    printStack();
    pop();
    printStack();
    pop();
    printStack();
    pop();
    printStack();
    pop();
    printStack();
    pop();
    printStack();
    return 0;
}