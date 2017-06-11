#include <stdio.h>

typedef struct element{
    int key;
} element;

// a[1:i]개의 정렬된 element배열에서 e의 적절한 위치를 찾아가는 함수.
void insert(element e, element a[], int i){
    element tmp = e;
    while(e.key < a[i].key){
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = e;
}

// a[1:i]을 비감소 키 순서대로 정렬.
void insertionSort(element a[], int n){
    int j;
    for(j = 2 ; j <= n; j++){
        insert(a[j], a, j-1);
    }
}

int main() {
    element el1;
    el1.key = 10;
    element el2;
    el2.key = 4;
    element el3;
    el3.key = 6;
    element el4;
    el4.key = 15;

    element e_list[] = {NULL, el1, el2, el3, el4};

    insertionSort(e_list, 4);

    for(int i = 1 ; i <= 4 ; i++){
        printf("%d\n", e_list[i].key);
    }
    printf("Hello, World!\n");
    return 0;
}