//time: 2026.4.17
//idea: 要进行四舍五入的操作，不然没办法通过

#include <cstdio>
int main(){
    int c1,c2;
    scanf("%d %d", &c1, &c2);
    int result = c2-c1;
    if(result % 100 >= 50) result = result / 100 + 1; //四舍五入
    else result = result / 100;
    int min = result %3600 / 60;
    int s = result % 60;
    int h = result / 3600;
    printf("%02d:%02d:%02d\n",h,min,s);
}