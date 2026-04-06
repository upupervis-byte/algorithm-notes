//time 2026.4.6
//idea: find the root using the properties of preorder and inorder sequences, then build the binary tree

#include <cstdio>
const int maxn = 50;

struct{
    int lchild;
    int rchild;
}Node[maxn];

int in[maxn];
int pre[maxn];

int create(int preL, int preR, int inL, int inR){   //node number
    if(preL > preR) return -1;
    int root = pre[preL];      //data
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == root) break;
    }
    int numleft = k - inL;
    Node[root].lchild = create(preL+1, preL + numleft, inL, k-1);
    Node[root].rchild = create(preL+numleft+1, preR, k+1, inR);
    return root;
}

void postorder(int root, bool &first){
    if(root == -1) return;
    postorder(Node[root].lchild, first);
    postorder(Node[root].rchild, first);
    if(!first) printf(" ");
    else first = false;
    printf("%d",root);
}

int main(){
    for(int i = 0; i < maxn; i++){      //set all node'lchild and rchild to -1 initially(初始化)
        Node[i].lchild = -1;
        Node[i].rchild = -1;
    }
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    int root = create(0, n-1, 0, n-1);
    bool first = true;
    postorder(root, first);
}