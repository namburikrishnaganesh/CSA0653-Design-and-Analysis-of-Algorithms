#include <stdio.h>
void add(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtract(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2], M6[2][2], M7[2][2];
    int temp1[2][2], temp2[2][2];
    add(A, A, temp1);
    add(B, B, temp2);
    multiply(temp1, temp2, M1);
    add(A, A, temp1);
    multiply(temp1, B, M2);
    subtract(B, B, temp1);
    multiply(A, temp1, M3);
    subtract(B, B, temp1);
    multiply(A, temp1, M4);
    add(A, A, temp1);
    multiply(temp1, B, M5);
    subtract(A, A, temp1);
    add(B, B, temp2);
    multiply(temp1, temp2, M6);
    subtract(A, A, temp1);
    add(B, B, temp2);
    multiply(temp1, temp2, M7);
    add(M1, M4, temp1);
    subtract(temp1, M5, temp2);
    add(temp2, M7, C);
    add(M3, M5, C);
    add(M2, M4, C);
    subtract(M1, M2, temp1);
    add(temp1, M3, temp2);
    add(temp2, M6, C);
}
void multiply(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void printMatrix(int M[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];
    strassen(A, B, C);
    printf("Resultant matrix:\n");
    printMatrix(C);
    return 0;
}