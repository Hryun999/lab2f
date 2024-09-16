#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void shell(int* items, int count) {
    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j -= gap) {
                items[j + gap] = items[j];
            }
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) {
    int i, j;
    int x, y;

    i = left;
    j = right;
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

int compare(const void* val1, const void* val2) {
    return (*(int*)val1 - *(int*)val2);
}

int main(void) {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    clock_t start, end;
    int size = 100000;

    int* a1 = (int*)malloc(sizeof(int) * size);
    int* b1 = (int*)malloc(sizeof(int) * size);
    int* c1 = (int*)malloc(sizeof(int) * size);
    int* d1 = (int*)malloc(sizeof(int) * size);

    int* a2 = (int*)malloc(sizeof(int) * size);
    int* a3 = (int*)malloc(sizeof(int) * size);

    int* b2 = (int*)malloc(sizeof(int) * size);
    int* b3 = (int*)malloc(sizeof(int) * size);

    int* c2 = (int*)malloc(sizeof(int) * size);
    int* c3 = (int*)malloc(sizeof(int) * size);

    int* d2 = (int*)malloc(sizeof(int) * size);
    int* d3 = (int*)malloc(sizeof(int) * size);

    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        a1[i] = rand() % 100 + 1;
    }
    memcpy(a2, a1, sizeof(int) * size);
    memcpy(a3, a1, sizeof(int) * size);

    start = clock();
    shell(a1, size);
    end = clock();
    printf("1. shell sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(a1);

    start = clock();
    qs(a2, 0, size - 1);
    end = clock();
    printf("1. qs sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(a2);

    start = clock();
    qsort(a3, size, sizeof(int), compare);
    end = clock();
    printf("1. qsort sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(a3);

    for (size_t i = 0; i < size; i++) {
        b1[i] = i * 2;
    }
    memcpy(b2, b1, sizeof(int) * size);
    memcpy(b3, b1, sizeof(int) * size);

    start = clock();
    shell(b1, size);
    end = clock();
    printf("2. shell sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(b1);

    start = clock();
    qs(b2, 0, size - 1);
    end = clock();
    printf("2. qs sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(b2);

    start = clock();
    qsort(b3, size, sizeof(int), compare);
    end = clock();
    printf("2. qsort sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(b3);

    for (size_t i = 0; i < size; i++) {
        c1[i] = i * -2;
    }
    memcpy(c2, c1, sizeof(int) * size);
    memcpy(c3, c1, sizeof(int) * size);

    start = clock();
    shell(c1, size);
    end = clock();
    printf("3. shell sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(c1);

    start = clock();
    qs(c2, 0, size - 1);
    end = clock();
    printf("3. qs sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(c2);

    start = clock();
    qsort(c3, size, sizeof(int), compare);
    end = clock();
    printf("3. qsort sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(c3);

    for (size_t i = 0; i < size; i++) {
        if (i <= size / 2) {
            d1[i] = i * 2;
        }
        else {
            d1[i] = (size - 1 - i) * 2;
        }
    }
    memcpy(d2, d1, sizeof(int) * size);
    memcpy(d3, d1, sizeof(int) * size);

    start = clock();
    shell(d1, size);
    end = clock();
    printf("4. shell sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(d1);

    start = clock();
    qs(d2, 0, size - 1);
    end = clock();
    printf("4. qs sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(d2);

    start = clock();
    qsort(d3, size, sizeof(int), compare);
    end = clock();
    printf("4. qsort sort: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(d3);

    return 0;
}
