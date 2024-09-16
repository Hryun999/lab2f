#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

    clock_t start, end;
    int i = 0, j = 0, r;
    int size = 10000;
    int elem_c;

    int** a = (int**)malloc(sizeof(int*) * size);
    int** b = (int**)malloc(sizeof(int*) * size);
    int** c = (int**)malloc(sizeof(int*) * size);

    for (int i = 0; i < size; i++) {
        a[i] = (int*)malloc(sizeof(int) * size);
        b[i] = (int*)malloc(sizeof(int) * size);
        c[i] = (int*)malloc(sizeof(int) * size);
    }

    srand(time(NULL));
    while (j < size) {
        a[i][j] = rand() % 100 + 1;
        j++;
    }
    i++;

    srand(time(NULL));
    i = 0; j = 0;
    while (i < size) {
        while (j < size) {
            b[i][j] = rand() % 100 + 1;
            j++;
        }
        i++;
    }

    start = clock();
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            elem_c = 0;
            for (r = 0; r < size; r++) {
                elem_c = elem_c + a[i][r] * b[r][j];
                c[i][j] = elem_c;
            }
        }
    }
    end = clock();
    printf("%f\n", (float)(end - start) / CLOCKS_PER_SEC);

    return 0;

}