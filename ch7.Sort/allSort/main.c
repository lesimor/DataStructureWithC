#include <stdio.h>
#define MAX 100

void bubbleSort(int arr[], int size);
void selectionSort(int *arr, int size);
void insertionSort(int arr[], int size);
void mergeSort(int arr[], int low, int high);
void quickSort(int arr[], int left, int right);

int tmp[MAX];

int main() {
    int arr[]={8,3,1,7,7,9,11,21,86,32,64,87,21,64,12};

    int size = 15;

//    bubbleSort(arr, size);
//    selectionSort(arr, size);
//    insertionSort(arr, size);
//    mergeSort(arr, 0, size - 1);
    quickSort(arr, 0, size - 1);

    for(int i = 0  ; i < size ; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void SWAP(int arr[], int idx1, int idx2){
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

void bubbleSort(int arr[], int size){
    int i, j;
    for(i = 0; i <= size - 1 ; i++){
        for(j = 0 ; j <= size - 1 - 1 - i ; j++){
            if(arr[j] > arr[j+1]) SWAP(arr, j, j+1);
        }
    }
}

void selectionSort(int *arr, int size){
    int pointing_idx, comparing_idx, min_value_idx;
    for(pointing_idx = 0; pointing_idx <= size - 1 ; pointing_idx++){
        min_value_idx = pointing_idx;
        for(comparing_idx = pointing_idx + 1 ; comparing_idx <= size - 1 ; comparing_idx++){
            if(arr[comparing_idx] < arr[min_value_idx]){
                min_value_idx = comparing_idx;
            }
        }
        if(pointing_idx != min_value_idx) SWAP(arr, pointing_idx, min_value_idx);
    }
}

void insertionSort(int arr[], int size){
    int p_idx, s_idx;
    for(p_idx = 1 ; p_idx <= size - 1 ; p_idx++){
        for(s_idx = p_idx ; s_idx >= 1 ; s_idx--){
            if(arr[s_idx - 1] > arr[s_idx]){
                SWAP(arr, s_idx - 1, s_idx);
            }
        }
    }
}

void merge(int arr[], int low , int mid,  int high){
    int l1 = low, l2 = mid + 1, tmp_idx = low;
    while(l1 <= mid && l2 <= high){
        if(arr[l1] < arr[l2]){
            tmp[tmp_idx++] = arr[l1++];
        } else {
            tmp[tmp_idx++] = arr[l2++];
        }
    }
    if(l1 > mid){
        while(l2 <= high){
            tmp[tmp_idx++] = arr[l2++];
        }
    }
    if(l2 > high){
        while(l1 <= mid){
            tmp[tmp_idx++] = arr[l1++];
        }
    }
    for(int i = 0; i <= high ; i++){
        arr[i] = tmp[i];
    }
}

void mergeSort(int arr[], int low, int high){
    int mid = (low + high)/2;

    if(low < high){
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }

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