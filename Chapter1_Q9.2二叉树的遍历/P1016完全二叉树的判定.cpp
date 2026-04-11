//time: 2026.4.11
//idea: 

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 64;

int main(){
    int n;
    scanf("%d", &n);
    int left[maxn], right[maxn];
    for(int i = 0; i < n; i++){
        scanf("%d %d",&left[i], &right[i]);
    }
    queue<int> q;
    q.push(0);
    bool hasNull = false;
    bool isComplete = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == -1) hasNull = true;
        else{
            if(hasNull){
                isComplete = false;
                break;
            }
            else{
                q.push(left[u]);
                q.push(right[u]);
            }
        }
    }
    if(isComplete) printf("Yes");
    else printf("No");
}