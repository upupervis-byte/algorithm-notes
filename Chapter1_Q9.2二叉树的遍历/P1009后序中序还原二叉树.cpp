//time 2026.4.6
//idea: find the root using the properties of postorder and inorder sequences(序列), then build the binary tree

#include <cstdio>
const int maxn = 50;

struct node{
    int lchild;
    int rchild;
}Node[maxn];

int post[maxn];
int in[maxn];

int create(int postL, int postR, int inL, int inR){
    if(postL > postR) return -1;
    int root = post[postR];
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == root) break;
    }
    int numleft = k - inL;
    Node[root].lchild = create(postL, postL+numleft-1, inL, k-1);
    Node[root].rchild = create(postL+numleft, postR-1, k+1, inR);
    return root;
}

void preorder(int root, bool &first){
    if(root == -1) return;
    if(!first) printf(" ");
    else first = false;
    printf("%d", root);
    preorder(Node[root].lchild, first);
    preorder(Node[root].rchild, first);
}

int main(){
    for(int i = 0; i < maxn; i++){
        Node[i].lchild = -1;
        Node[i].rchild = -1;
    }
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    int root = create(0, n-1, 0, n-1);
    bool first = true;
    preorder(root, first);
}