//time: 2026.4.17
//idea: 要去枚举A的每一个数字，可以用字符串存储数字，或者是直接用long long也可以，通过取余数的方法把每一个数字拿出来比较，之后再除掉那一个数，利用循环实现枚举

#include <cstdio>
int main(){
    long long A,B;
    int D1, D2;
    scanf("%lld %d %lld %d",&A, &D1, &B, &D2);
    int pa = 0,pb = 0;
    while(A != 0){
        if(A % 10 == D1) pa = pa*10 + D1;
        A /= 10;
    }
    while(B != 0){
        if(B % 10 == D2) pb = pb * 10 + D2;
        B /= 10;
    }
    printf("%lld\n", pa + pb);
}