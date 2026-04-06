//time 2026.4.6
//idea: just perform regular preorder and inorder traversals by swapping(交换) the lchild and rchild when inputting

#include <cstdio>
const int maxn = 50;

struct node{
    int lchild;
    int rchild;
}Node[maxn];

void preorder(int root, bool &first){
    if(root == -1) return;
    if(!first) printf(" ");
    else first = false;
    printf("%d", root);
    preorder(Node[root].lchild, first);
    preorder(Node[root].rchild, first);
}

void inorder(int root, bool &first){
    if(root == -1) return;
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
        int temp = left;
        Node[i].rchild = temp;
        temp = right;
        Node[i].lchild = temp;
    }
    bool first = true;
    preorder(0, first);
    printf("\n");
    first = true;
    inorder(0, first);
}