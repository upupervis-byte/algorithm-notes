//time: 2026.4.7
//idea: 哦耶还挺简单peace of cake bro

#include <cstdio>
int main(){
    int n;
    scanf("%d", &n);
    int j1,j2,y1,y2;
    int c1 = 0,c2 = 0;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &j1, &j2, &y1, &y2);
        if((j2 == j1 + y1) && !(y2 == j1 + y1)) c2++;
        if((y2 == j1 + y1) && !(j2 == j1 + y1)) c1++;
    }
    printf("%d %d\n", c1, c2);
}