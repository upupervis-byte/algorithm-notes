//time: 2026.4.12
//idea:

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 50;

struct node{
    int layer;
    vector<int> child;
}Node[maxn];

void LayerOrder(int root){
    queue<int> q;
    q.push(root);
    Node[root].layer = 1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int child: Node[front].child){
            Node[child].layer = Node[front].layer + 1;
            q.push(child);
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
    bool first = true;
    for(int i = 0; i < n; i++){
        if(!first) printf(" ");
        else first = false;
        printf("%d",Node[i].layer);
    }
}