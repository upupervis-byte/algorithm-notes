//time 2026.4.5
//idea: 1.push the node into queue q
//      2.pop the front element from the queue and visit it
//      3.if the current node has a lchild, push the lchild into queue q
//      4.if the current node has a rchild, push it into queue q
//      5.repeat step2(返回，重复) until the queue becomes empty

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 50;

struct node{
    int lchild;
    int rchild;
}Node[maxn];

void LayerOrder(int root, bool &first){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(!first) printf(" ");
        else first = false;
        printf("%d", now);
        if(Node[now].lchild != -1) q.push(Node[now].lchild);
        if(Node[now].rchild != -1) q.push(Node[now].rchild);
    }
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
    bool first = true;
    LayerOrder(0, first);
    printf("\n");
}