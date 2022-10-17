/*
    sorting_building.c: 스마트 도시에 있는 빌딩들의 높이 값들을 입력 받아 배열에 저장하고, 높이가 낮은 빌딩 높이부터 높은 높이까지 차례로 순서를 맞추는 프로그램
    정민기 2022-10-18
 */
#include <stdio.h>
#define MAX 10000
int height[MAX];
int idx[MAX];
int main(void) {
    int n, i, pass, temp;
    printf("스마트 도시의 빌딩 수를 입력하시오: ");
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        printf("빌딩 %d: ", i+1);
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

    printf("오름차순으로 정렬된 빌딩은 다음과 같습니다.\n");
    for (i=0; i<n; i++) printf("빌딩 %d: %d\n", idx[i]+1, height[i]);
}