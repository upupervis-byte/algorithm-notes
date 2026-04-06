//time 2026.4.6
//idea: set the root node's layer to 1 before enqueueing it. For each node now, assign its left and right child a layer number of now.layer + 1 before enqueueing them

#include <cstdio>
#include <queue>
#include <algorithm>    //the max function requies this header file
using namespace std;
const int maxn = 50;

struct{
    int lchild;
    int rchild;
}Node[maxn];

int layer[maxn];

int LayerOrder(int root){
    if(root == -1) return 0;
    queue<int> q;
    layer[root] = 1;
    q.push(root);
    int maxLayer = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(Node[now].lchild != -1){
            layer[Node[now].lchild] = layer[now]+1;
            maxLayer = max(maxLayer, layer[Node[now].lchild]);
//layer[now]: level of current node(当前结点的层数)
//layer[now]+1: level of child node(parent level + 1)
//layer[Node[now].rchild]: stores the level of the right child
//after assighment(赋值后), the right child's level is saved in the layer array
            q.push(Node[now].lchild);
        }
        if(Node[now].rchild != -1){
            layer[Node[now].rchild] = layer[now] + 1;
            maxLayer = max(maxLayer, layer[Node[now].rchild]); 
            q.push(Node[now].rchild);
        }
    }
    return maxLayer;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int left, right;
        scanf("%d %d", &left, &right);
        Node[i].lchild = left;
        Node[i].rchild = right;
    }
    int height = LayerOrder(0);
    printf("%d",height);
}