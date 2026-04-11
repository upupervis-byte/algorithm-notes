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

void LayerOrder(int root, bool &first){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int front = q.front();
        if(!first) printf(" ");
        else first = false;
        printf("%d", front);
        q.pop();
        for(int i = 0; i < Node[front].child.size(); i++){
            q.push(Node[front].child[i]);
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
    bool first = true;
    LayerOrder(0, first);
}