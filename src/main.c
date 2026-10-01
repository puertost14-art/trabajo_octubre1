
#include <stdint.h>

void swap(uint64_t *A, std::uint64_t p1, std::uint64_t p2) const {
    std::uint64_t temp = A[p1];
    A[p1] = A[p2];
    A[p2] = temp;
}

int partition(uint64_t *A, int p, int r) const {
    std::uint64_t x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A, i, j);
        }

    }


    swap(A, i + 1, r);
    return i + 1;
}

void quick_sort(uint64_t *A, int p, int r) const {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}


int main(){

    return 0;
}