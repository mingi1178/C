/*
    sorting_building.c: ����Ʈ ���ÿ� �ִ� �������� ���� ������ �Է� �޾� �迭�� �����ϰ�, ���̰� ���� ���� ���̺��� ���� ���̱��� ���ʷ� ������ ���ߴ� ���α׷�
    ���α� 2022-10-18
 */
#include <stdio.h>
#define MAX 10000
int height[MAX];
int idx[MAX];
int main(void) {
    int n, i, pass, temp;
    printf("����Ʈ ������ ���� ���� �Է��Ͻÿ�: ");
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        printf("���� %d: ", i+1);
        scanf("%d", &height[i]);
        idx[i] = i;
    }
    
    for (pass=1; pass<n; pass++) {
        for (i=0; i<n-pass; i++) {
            if (height[i] > height[i + 1]) {
                temp = height[i];
                height[i] = height[i + 1];
                height[i + 1] = temp;
                temp = idx[i];
                idx[i] = idx[i + 1];
                idx[i + 1] = temp;
            }
        }
    }

    printf("������������ ���ĵ� ������ ������ �����ϴ�.\n");
    for (i=0; i<n; i++) printf("���� %d: %d\n", idx[i]+1, height[i]);
}