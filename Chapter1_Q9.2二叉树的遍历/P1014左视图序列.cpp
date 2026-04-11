//time: 2026.4.11
//idea: use BFS to traverse the tree level by level and output the first node of each level of the left view.

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 50;

int main(){
    int n;
    scanf("%d",&n);
    int left[maxn], right[maxn];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &left[i], &right[i]);
    }
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        printf("%d",q.front());
        int size = q.size();
        for(int i = 0; i < size; i++){
            int u = q.front();
            q.pop();
            if(left[u] != -1) q.push(left[u]);
            if(right[u] != -1) q.push(right[u]);
        }
        if(!q.empty()) printf(" ");
    }
}