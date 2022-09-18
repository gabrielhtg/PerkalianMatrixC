#include<stdio.h>
#include<stdlib.h>

int **array1, **array2, **array3;
int i, j, temp;

int **operasi (int a, int b) {
    int **matrix = (int **) malloc (a *sizeof(int*)); // dialokasikan baris matrix sebanyak a
    for (i = 0; i < a; i++) {
        matrix[i] = (int *) malloc (b *sizeof(int)); // dialokasikan row matrix sebanyak b
    } 

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            printf("Masukkan input untuk lokasi matrix %dx%d : ", i + 1, j + 1);
            scanf("%d", &temp);
            matrix[i][j] = temp;
        }
    }

    return matrix;
}

int **perkalian (int **array1, int **array2, int m1, int n1, int m2, int n2) {
    int x, y;
    int matrixA[(m1 * n2) * m2];
    int matrixB[(m1 * n2) * m2];

    x = 0;
    for (y = 0; y < m1; y++) {
        for (i = 0; i < m1; i++) {
            for (j = 0; j < n1; j++) {
                matrixA[x] = array1[y][j];
                x++;
            }
        }
    }
    
    x = 0;
    for (y = 0; y < m1; y++) {
        for (j = 0; j < n2; j++) {
            for (i = 0; i < m2; i++) {
                matrixB[x] = array2[i][j];
                x++;
            }
        }
    }

    int **matrix = (int **) malloc (m1 *sizeof(int*));
    for (i = 0; i < m1; i++) {
        matrix[i] = (int *) malloc (n2 *sizeof(int));
    } 

    x = 0;
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
             temp = 0;
            for (y = 0; y < n1; y++) {
                temp = temp + matrixA[x] * matrixB[x];
                x++;
            }
            
            matrix[i][j] = temp;
        }
    }
    
    return matrix;
}

int main() {
    int m1, n1, m2, n2;

    printf("------------------------------------------------\n");
    printf("Array 1\n");
    printf("------------------------------------------------\n");
    printf("Masukkan ordo matrix pertama : ");
    scanf("%dx%d", &m1, &n1);
    printf("------------------------------------------------\n");
    printf("Array 2\n");
    printf("------------------------------------------------\n");
    printf("Masukkan ordo matrix kedua   : ");
    scanf("%dx%d", &m2, &n2);

    if (n1 == m2) {
        printf("------------------------------------------------\n");
        printf("                  Matrix A\n");
        printf("------------------------------------------------\n");
        array1 = operasi(m1, n1);
        printf("------------------------------------------------\n");

        for (i = 0; i < m1; i++) {
            for (j = 0; j < n1; j++) {
                printf("   %d", array1[i][j]);
            }
            printf("\n");
        }


        printf("------------------------------------------------\n");
        printf("                   Matrix B\n");
        printf("------------------------------------------------\n");
        array2 = operasi(m2, n2);
        printf("------------------------------------------------\n");

        for (i = 0; i < m2; i++) {
            for (j = 0; j < n2; j++) {
                printf("   %d", array2[i][j]);
            }
            printf("\n");
        }
        printf("------------------------------------------------\n");

        array3 = perkalian(array1, array2, m1, n1, m2, n2);

        printf("             Matrix A x Matrix B\n");
        printf("------------------------------------------------\n");

        for (i = 0; i < m1; i++) {
            for (j = 0; j < n2; j++) {
                printf("   %d", array3[i][j]);
            }
            printf("\n");
        }

        // printf("%d",array3[0][0]);

        printf("------------------------------------------------\n");
    }

    else {
        printf("Tidak dapat dilakukan perkalian matrix!\\n");
    }
}