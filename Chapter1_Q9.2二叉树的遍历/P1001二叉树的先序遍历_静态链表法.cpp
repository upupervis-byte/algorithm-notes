//*time: 2026.4.5
//*idea: the core idea is same like B1001, the difference is that B1001 uses pointers(指针), whereas P1001 uses array indices(数组下标)

#include <cstdio>
const int maxn = 50;

struct node{
    int lchild;
    int rchild;
}Node[maxn];

void preorder(int root, bool &first){
    if(root == -1){
        return;
    }
    if(!first) printf(" ");
    else first = false;
    printf("%d", root);
    preorder(Node[root].lchild, first);
    preorder(Node[root].rchild, first);
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
    preorder(0, first);
    printf("\n");
}