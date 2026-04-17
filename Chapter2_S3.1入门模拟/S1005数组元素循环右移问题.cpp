//time: 2026.4.17
//idea: 实现数组右移动，不要使用替换，直接在输出改动，实现右移

#include <cstdio>
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        if(i > 0) printf(" ");
        printf("%d\n",a[(n-m+i)%n]); //这里要%n是为了防止数组越界问题，必须要%n
    }
}