//time: 2026.4.17
//idea: 注意点： sum要用longlong来定义防止数组越界

#include <cstdio>
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        long long A,B,C;
        scanf("%lld %lld %lld", &A, &B, &C);    //要用%lld来读取才可以
        long long sum = A+B;
        if(sum > C) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
}