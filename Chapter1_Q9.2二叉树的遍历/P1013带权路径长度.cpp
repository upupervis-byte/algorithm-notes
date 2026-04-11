//time: 2026.4.11
//idea: use DFS traverse thr tree and calculate the total weighted parh length of all leaces.

#include <cstdio>
const int maxn = 50;

int left[maxn],right[maxn];
int w[maxn];
int ans = 0;

void dfs(int u, int lengthCur_sum){
    if(left[u] == -1 && right[u] == -1){
        int x = w[u];
        int sum = x * lengthCur_sum;
        ans += sum;
    }
    if(left[u] != -1) dfs(left[u], lengthCur_sum+1);
    if(right[u] != -1) dfs(right[u], lengthCur_sum+1);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d", &w[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d %d", &left[i], &right[i]);
    }
    dfs(0,0);
    printf("%d",ans);
}