/*
    searching_building.c: 스마트 도시에 있는 빌딩들의 높이 값들을 입력 받아 배열에 저장하고, 특정 높이 값이 들어 왔을 때, 현재 배열에 저장된 값 중에서 가장 비슷한 높이의 빌딩 높이를 출력하는 프로그램
    정민기 2022-10-17
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
    printf("스마트 도시의 빌딩 수를 입력하시오: ");
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        printf("빌딩 %d: ", i+1);
        scanf("%d", &height[i]);
    }
    
    printf("찾고 싶은 높이를 입력하시오: ");
    scanf("%d", &key);
    for (i=0, r=1, d=abs(key-height[0]); i<n; i++) {
        if (height[i] == key) {
            printf("빌딩 %d입니다.", i+1);
            return 0;
        }
        else if(abs(key-height[i]) < d){
            d = abs(key-height[i]);
            r = i+1;
        }
    }
    printf("원하는 빌딩은 없습니다. 가장 비슷한 높이의 빌딩은 빌딩 %d입니다.", r);
}