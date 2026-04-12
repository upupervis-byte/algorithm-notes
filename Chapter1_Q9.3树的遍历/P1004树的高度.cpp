//time: 2026.4.11
//idea: 

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 50;

struct node{
    vector<int> child;
}Node[maxn];

int height = 0;

void LayerOrder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        height++;
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++){
            int front = q.front();
            q.pop();
            for(int i = 0; i < Node[front].child.size(); i++){
                q.push(Node[front].child[i]);
            }
        }

    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            int child;
            scanf("%d", &child);
            Node[i].child.push_back(child);
        }
    }
    LayerOrder(0);
    printf("%d", height);
}