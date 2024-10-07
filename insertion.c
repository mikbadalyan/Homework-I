#include <stdio.h>

void insert(int array[], int n) {
    int point = array[n - 1];
    int j = n - 2;

    while (j >= 0 && array[j] > point) {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = point;
}


void recurcive(int array[], int n) {
    
    if (n <= 1) {
        return;
    }
    recurcive(array, n - 1);
    insert(array, n);
}

void printarrayay(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {5, 78, 15, 11, 132, 485, 10, 1, 7, 99, 150};
    int n = sizeof(array) / sizeof(array[0]);
    //printf("%d", n);
    printf("First Array: \n");
    printarrayay(array, n);

    recurcive(array, n);

    printf("Sorted array: \n");
    printarrayay(array, n);

    return 0;
}
