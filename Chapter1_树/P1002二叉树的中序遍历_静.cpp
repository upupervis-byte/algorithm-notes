//time: 2026.4.5
//idea: the core idea is to output the lchild first, followed by the root and rchild;

#include <cstdio>
const int maxn = 50;

struct node{
    int lchild;
    int rchild;
}Node[maxn];

void inorder(int root, bool &first){
    if(root == -1){
        return;
    }
    inorder(Node[root].lchild, first);
    if(!first) printf(" ");
    else first = false;
    printf("%d", root);
    inorder(Node[root].rchild, first);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int left, right;
        scanf("%d %d",&left, &right);
        Node[i].lchild = left;
        Node[i].rchild = right;
    }
    bool first = true;
    inorder(0, first);
    printf("\n");
}