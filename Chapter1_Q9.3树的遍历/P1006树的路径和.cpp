//time:2026.4.12
//idea:

#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 50;

struct node{
    vector<int> child;
}Node[maxn];

int ans = 0;
int w[maxn];

void dfs(int u, int cur_sum){
    cur_sum += w[u];
    if(Node[u].child.empty()){
        ans += cur_sum;
        return;
    }
    else{
        for(int i = 0; i < Node[u].child.size(); i++){
            int v = Node[u].child[i];
            dfs(v, cur_sum);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &w[i]);
    }
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            int child;
            scanf("%d", &child);
            Node[i].child.push_back(child);
        }
    }
    dfs(0,0 );
    printf("%d", ans);
}