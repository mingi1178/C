/*
    searching_building.c: ����Ʈ ���ÿ� �ִ� �������� ���� ������ �Է� �޾� �迭�� �����ϰ�, Ư�� ���� ���� ��� ���� ��, ���� �迭�� ����� �� �߿��� ���� ����� ������ ���� ���̸� ����ϴ� ���α׷�
    ���α� 2022-10-17
 */
#include <stdio.h>
#define MAX 10000
int abs(int a) {
    if (a<0) return -a;
    else return a;
}
int main(void) {
    int height[MAX] = {0};
    int n, key, i;
    int r, d;
    printf("����Ʈ ������ ���� ���� �Է��Ͻÿ�: ");
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        printf("���� %d: ", i+1);
        scanf("%d", &height[i]);
    }
    
    printf("ã�� ���� ���̸� �Է��Ͻÿ�: ");
    scanf("%d", &key);
    for (i=0, r=1, d=abs(key-height[0]); i<n; i++) {
        if (height[i] == key) {
            printf("���� %d�Դϴ�.", i+1);
            return 0;
        }
        else if(abs(key-height[i]) < d){
            d = abs(key-height[i]);
            r = i+1;
        }
    }
    printf("���ϴ� ������ �����ϴ�. ���� ����� ������ ������ ���� %d�Դϴ�.", r);
}