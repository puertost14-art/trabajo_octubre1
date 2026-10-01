
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

void print_array(const uint64_t *A, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%" PRIu64, A[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

void swap(uint64_t *A, uint64_t p1, uint64_t p2)
{
    uint64_t temp = A[p1];
    A[p1] = A[p2];
    A[p2] = temp;
}

int partition(uint64_t *A, int p, int r)
{
    uint64_t x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap(A, i, j);
        }
    }

    swap(A, i + 1, r);
    return i + 1;
}

void quick_sort(uint64_t *A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

int main()
{
    uint64_t arr[] = {9, 4, 7, 2, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Antes: ");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("Despues: ");
    print_array(arr, n);

    return 0;
}