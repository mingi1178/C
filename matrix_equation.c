/*
    matrix_equation.c: Ax=b���� A ��İ� b ������ �Է� �޾�, x ���� ���ϴ� ���α׷�
    ���α� 2022-10-18
 */
#include <stdio.h>
int main(void) {
    int A[3][3];
    int inverseA[3][3];
    int b[3];
    double x[3];
    int i, j, detA;

    // �Է¹ޱ�
    printf("A(3x3 ���)�� �Է��Ͻÿ�.\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("b�� �Է��Ͻÿ�.\n");
    for (i=0; i<3; i++) {
        scanf("%d", &b[i]);
    }
    
    // ����� ���ϱ�
    detA = A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1]) - A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0]) + A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
    inverseA[0][0] = A[1][1]*A[2][2] - A[1][2]*A[2][1];
    inverseA[0][1] = A[0][2]*A[2][1] - A[0][1]*A[2][2];
    inverseA[0][2] = A[0][1]*A[1][2] - A[0][2]*A[1][1];
    inverseA[1][0] = A[1][2]*A[2][0] - A[1][0]*A[2][2];
    inverseA[1][1] = A[0][0]*A[2][2] - A[0][2]*A[2][0];
    inverseA[1][2] = A[0][2]*A[1][0] - A[0][0]*A[1][2];
    inverseA[2][0] = A[1][0]*A[2][1] - A[1][1]*A[2][0];
    inverseA[2][1] = A[0][1]*A[2][0] - A[0][0]*A[2][1];
    inverseA[2][2] = A[0][0]*A[1][1] - A[0][1]*A[1][0];

    // x ���ϱ�
    for (i=0; i<3; i++) {
        x[i] = 0;
        for (j=0; j<3; j++){
            x[i] += 1.0 / detA * inverseA[i][j] * b[j];
        }
    }
    
    // x ���
    for (i=0; i<3; i++) printf("x%d = %lf\n", i+1, x[i]);
}