#include <stdio.h>
#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1


// 스택에 들어갈 element의 타입 정의
typedef struct{
    int key;
} element;

// 스택 배열 선언
element stack[MAX_STACK_SIZE];

// top위치
int top = -1;

// 스택 관련 함수
// 스택이 비어있는지 확인.
int isEmpty(){
    return top <= -1 ? TRUE : FALSE;
}

// 스택이 가득 차있는지 확인.
int isFull(){
    return top >= MAX_STACK_SIZE ? TRUE : FALSE;
}

// 스택에 element를 push
void push(int num){
    printf("%d 삽입!!\n", num);
    stack[++top].key = num;
}

// 스택으로부터 element를 pop하고 해당 요소의 key를 반환
int pop(){
    if(isEmpty()){
        printf("스택이 비어있어서 pop할 수 없습니다.");
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
        printf("-----stack------\n");
        for(i = top ; i >= 0 ; i--){
            printf("|| %d ||\n", stack[i].key);
        }
        printf("----------------\n");
    }

}

int main() {
    printStack();
    push(3);
    printStack();
    push(2);
    printStack();
    push(5);
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
    return 0;
}