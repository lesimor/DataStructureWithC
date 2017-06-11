#include <stdio.h>

typedef struct element {
    int key;
}element;

void swap(element e[], int i, int j){
    element temp;
    temp = e[i];
    e[i] = e[j];
    e[j] = temp;
}

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    int temp;
    do {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i<= j) {
            //swap
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            // i 1증가 / j 1감소
            i++;
            j--;
        }
    } while (i<= j);

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);

    if (i < right)
        quickSort(arr, i, right);
}
int main() {
    int arr[]={8,3,1,7,7,9,11,21,86,32,64,87,21,64,12};

    int size = 15;


    quickSort(arr, 0, size-1);

    printf("Hello, World!\n");
    for(int i = 0 ; i < size; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}