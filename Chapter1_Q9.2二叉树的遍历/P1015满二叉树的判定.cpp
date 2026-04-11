//time: 2026.4.11
//idea: calculate the height of the tree, then check whether the total number of nodes equals 2^height - 1

#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 64;

int main(){
    int n;
    scanf("%d", &n);
    int left[maxn];
    int right[maxn];
    for(int i = 0; i < n; i++){
    scanf("%d %d", &left[i], &right[i]);
    }
    queue<int> q;
    q.push(0);
    int layer = 0;
    while(!q.empty()){
        int size = q.size();
        layer++;
        for(int i = 0; i < size; i++){
            int u = q.front();
            q.pop();
            if(left[u] != -1){
                q.push(left[u]);
            }
            if(right[u] != -1){
                q.push(right[u]);
            }
        }
    }
    double result = (int)pow(2.0, layer) - 1;
    if(result == n) printf("Yes");
    else printf("No");
}