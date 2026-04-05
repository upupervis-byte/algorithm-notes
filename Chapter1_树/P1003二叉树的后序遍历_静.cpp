//time 2026.4.5
//idea: the core idea is to output the lchild at first, followed by rchild and root

#include <cstdio>
const int maxn = 50;

struct node{
    int lchild;
    int rchild;
}Node[maxn];

void postorder(int root, bool &first){
    if(root == -1) return;
    postorder(Node[root].lchild, first);
    postorder(Node[root].rchild, first);
    if(!first) printf(" ");
    else first = false;
    printf("%d", root);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int left, right;
        scanf("%d %d", &left, &right);
        Node[i].lchild = left;
        Node[i].rchild = right;
    }
    bool first = true;
    postorder(0,first);
    printf("\n");
}
