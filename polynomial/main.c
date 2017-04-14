#include <stdio.h>
#define MAX_TERMS 100
#define COMPARE(A, B) (A) < (B) ? -1 : ((A)==(B) ? 0 : 1)

typedef struct {
    float coef;
    int expon;
} polynomial;
polynomial terms[MAX_TERMS];
int avail = 5;
void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD);
void attach(float coefficient, int exponent);
void printPoly(int start_idx, int end_idx);
int main() {
//    printf("%d", COMPARE(1,2));
    // startA = 0
    // finishA = 1
    terms[0].coef = 1.1;
    terms[0].expon = 10;
    terms[1].coef = 3.0;
    terms[1].expon = 0;

    // startB = 2
    // finishB = 4
    terms[2].coef = 4.1;
    terms[2].expon = 2;
    terms[3].coef = 1.3;
    terms[3].expon = 1;
    terms[4].coef = 1.1;
    terms[4].expon = 0;

    int result_start_idx, result_end_idx;

    padd(0, 1, 2, 4, &result_start_idx, &result_end_idx);

//    printf("result_idx: %d, end_idx: %d", result_start_idx, result_end_idx);

    printPoly(result_start_idx, result_end_idx);

    return 0;
}

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD){
    float coefficient;
    *startD = avail;
    while(startA <= finishA && startB <= finishB){
        switch(COMPARE(terms[startA].expon, terms[startB].expon)){
            case -1:
                attach(terms[startB].coef, terms[startB].expon);
                startB++;
                break;
            case 0:
                coefficient = terms[startA].coef + terms[startB].coef;
                if(coefficient)
                    attach(coefficient, terms[startA].expon);
                startA++;
                startB++;
                break;
            case 1:
                attach(terms[startA].coef, terms[startA].expon);
                startA++;
                break;
        }
    }
    for(; startA <= finishA ; startA++)
        attach(terms[startA].coef, terms[startB].expon);
    for(; startB <= finishB ; startB++)
        attach(terms[startB].coef, terms[startB].expon);
    *finishD = avail - 1;
}

void attach(float coefficient, int exponent){
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}

void printPoly(int start_idx, int end_idx){
    for(;start_idx <= end_idx; start_idx++){
        if(start_idx != end_idx){
            printf("%.1fx^%d + ", terms[start_idx].coef, terms[start_idx].expon);
        } else {
            printf("%.1fx^%d", terms[start_idx].coef, terms[start_idx].expon);
        }

    }
}