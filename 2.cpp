#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;

    do {
        while (A[i] <= pivot) i++;
        while (A[j] > pivot) j--;

        if (i < j) swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

void quicksort(int A[], int l, int h) {
    if (l < h) {
        int j = partition(A, l, h);

        printf("pivot: %d\n", A[j]);

        printf("pass: ");
        for (int k = l; k <= h; k++) {
            if (k == j) {
                printf("[%d] ", A[k]);
            } else {
                printf("%d ", A[k]);
            }
        }
        printf("\n");

        quicksort(A, l, j - 1);
        quicksort(A, j + 1, h);
    }
}

int remove_duplicates(int A[], int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    int j = 0; 
    for (int i = 0; i < n - 1; i++) {
        if (A[i] != A[i + 1]) {
            A[j++] = A[i];
        }
    }
    A[j++] = A[n - 1]; 
    return j; 
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];
    srand(time(0));

    printf("Randomly generated elements in the array: ");
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
        printf("%d ", A[i]);
    }
    printf("\n");

    clock_t start = clock();
    quicksort(A, 0, n - 1);
    n = remove_duplicates(A, n);  
    clock_t end = clock();

    double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000; 

    printf("After sorting and removing duplicates: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Time taken to sort the array: %.2f milliseconds\n", time_taken);

    return 0;
}
