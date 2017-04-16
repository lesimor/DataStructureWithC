#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

typedef struct {
    int col;    // 최대 행 갯수
    int row;    // 최대 열 갯수
    int value;  // 0이 아닌 값들의 갯수
} term;

term a[MAX_TERMS];
term b[MAX_TERMS];


void transpose_normal(term *a, term *b);
void print_sparse_matrix(term a[]);
void insert_element(term a[], int row, int col, int value);
void sparse_matrix_init(term a[], int row, int col);

int main() {
    sparse_matrix_init(a, 5, 4);

    insert_element(a, 1, 3, 4);
    insert_element(a, 5, 4, 2);
    insert_element(a, 3, 2, 2);
    insert_element(a, 1, 2, 2);
    insert_element(a, 2, 4, 2);
    insert_element(a, 3, 1, 2);
    insert_element(a, 4, 3, 2);
    insert_element(a, 3, 3, 2);

    print_sparse_matrix(a);

    transpose_normal(a, b);

    print_sparse_matrix(b);
    return 0;
}

void transpose_normal(term *a, term *b){
    // a의 전치행렬을 b로 옮긴다.
    int n, i, j, currentb;
    n = a[0].value; // 총 원소 수
    b[0].value = n;
    b[0].col = a[0].row;
    b[0].row = a[0].col;

    if(n >0){
        currentb = 1;
        for(i = 0 ; i < a[0].col ; i++){
            for(j = 1 ; j <= n ; j++){
                if(a[j].col == i){
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    b[currentb++].row = i;
                }
            }
        }
    }
}

void print_sparse_matrix(term a[]){
    int i, value_volume = a[0].value;
    printf("idx\trow\tcol\tvalue\n");
    for(i = 0 ; i <= value_volume ; i++){
        printf("%d\t%d\t%d\t%d\n", i, a[i].row, a[i].col, a[i].value);
    }
}

void insert_element(term a[], int row, int col, int value){

    // 잘못된 입력값 처리
    if(row >= a[0].row){
        printf("제한된 행을 초과하였습니다.\n입력된 행: %d\n행 크기: %d\n", row, a[0].row);
        return;
    }
    if(col >= a[0].col){
        printf("제한된 열을 초과하였습니다.\n입력된 열: %d\n열 크기: %d\n", col, a[0].col);
        return;
    }

    int current_value_volume = ++a[0].value;

    // 메모리 초과 에러처리
    if(current_value_volume >= MAX_TERMS){
        printf("할당된 메모리가 가득찼습니다.\n");
        return;
    }


    a[current_value_volume].row = row;
    a[current_value_volume].col = col;
    a[current_value_volume].value = value;
}

void sparse_matrix_init(term a[], int row, int col){
    a[0].row = row;
    a[0].col = col;
    a[0].value = 0;
}
