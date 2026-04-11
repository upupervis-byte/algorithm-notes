//time: 2026.4.11
//idea: use DFS to traverse the tree and calculate the total path sum for leaf nodes.

#include <cstdio>
const int maxn = 50;

int ans = 0;
int w[maxn];
int left[maxn],right[maxn];

void dfs(int u, int cur_sum){
    cur_sum += w[u];
    if(left[u] == -1 && right[u] == -1){
        ans += cur_sum;
        return;
    }
    if(left[u] != -1) dfs(left[u], cur_sum);
    if(right[u] != -1) dfs(right[u], cur_sum);
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
    printf("%d", ans);
}