//time 2026.4.5
//idea: 1.store lchild/rchild in an array
//      2.perform BFS/DFS from root(0) to record node levels
//        a.use a queue that stores(node number, level nuumber)
//        b.start by enqueueing the root(0,1)
//        c.each time, pop the front element and set level[node] = level number
//        d.then enqueue the left and right children with a level number of current level + 1
//        e.repeat until the queue is empty
//      3.print level[0] to level[n-1] separated by spaces, no trailing space(结尾无空格)

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 50;

struct node{
    int lchild;
    int rchild;
}Node[maxn];

int level[maxn];

void LevelOrder(int root){
    if(root == -1) return 0;
    queue<pair<int, int>> q;  // to store a pair of elements, we use pair<int,int>
    q.push({root, 1});
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        int now = front.first;   //the current node number
        int lv = front.second;   //the current level number
        level[now] = lv;         //record the level number
        int left = Node[now].lchild;
        int right = Node[now].rchild;
        if(left != -1) q.push({left, lv + 1});
        if(right != -1) q.push({right, lv + 1});
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d %d",&Node[i].lchild, &Node[i].rchild);
    }
    LevelOrder(0);
    for(int i = 0; i < n; i++){
        printf("%d", level[i]);
        if(i < n-1){
            printf(" ");
        }
    }
}