#include <stdio.h>

void readMatrix(int matrix[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[10][10], int b[10][10], int res[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int res[10][10], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[10][10], int res[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matA[10][10], matB[10][10], res[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter elements of Matrix A:\n");
    readMatrix(matA, r1, c1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter elements of Matrix B:\n");
    readMatrix(matB, r2, c2);

    if (r1 == r2 && c1 == c2) {
        printf("\nMatrix Addition:\n");
        addMatrices(matA, matB, res, r1, c1);
        displayMatrix(res, r1, c1);
    } else {
        printf("\nAddition not possible (dimensions must match).\n");
    }

    if (c1 == r2) {
        printf("\nMatrix Multiplication:\n");
        multiplyMatrices(matA, matB, res, r1, c1, c2);
        displayMatrix(res, r1, c2);
    } else {
        printf("\nMultiplication not possible (columns of A must equal rows of B).\n");
    }

    printf("\nTranspose of Matrix A:\n");
    transposeMatrix(matA, res, r1, c1);
    displayMatrix(res, c1, r1);

    return 0;
}
