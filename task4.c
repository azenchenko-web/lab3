#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n;
    printf("Введіть розмір масиву N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некоректний розмір\n");
        return 1;
    }

    int arr[n];
    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % 100;
    }

    printf("\n=== 1. Початковий масив ===\n");
    for (int i = 0; i < n; i++) {
        printf("Елемент %2d: значення = %d | адреса = %p\n",
               i, *(arr + i), (void *)(arr + i));
    }

    int *min_ptr = arr;
    int *max_ptr = arr;
    for (int *p = arr; p < arr + n; p++) {
        if (*p < *min_ptr) {
            min_ptr = p;
        }
        if (*p > *max_ptr) {
            max_ptr = p;
        }
    }

    printf("\n=== 2. Результати пошуку ===\n");
    printf("Мінімальний елемент: значення = %d | адреса = %p\n",
           *min_ptr, (void *)min_ptr);
    printf("Максимальний елемент: значення = %d | адреса = %p\n",
           *max_ptr, (void *)max_ptr);

    int tmp = *min_ptr;
    *min_ptr = *max_ptr;
    *max_ptr = tmp;

    printf("\n=== 3. Результуючий масив після обміну ===\n");
    for (int i = 0; i < n; i++) {
        printf("Елемент %2d: значення = %d | адреса = %p\n",
               i, *(arr + i), (void *)(arr + i));
    }

    return 0;
}