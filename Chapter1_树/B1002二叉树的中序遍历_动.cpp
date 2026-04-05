//*time: 2026.4.5
//*idea: same like P1002

#include <cstdio>
const int maxn = 50;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int n;
node* Node[maxn];
void inorder(node* root, bool &first){
    if(root == NULL){
        return;
    }
    inorder(root->lchild, first);
    if(!first) printf(" ");
    else first = false;
    printf("%d",root->data);
//we need to include "first" in all preorder sentences to judge whether an element is the first one
    inorder(root->rchild, first);
}
int main(){
    scanf("%d",&n);
//this for loop performs initialization
    for(int i = 0; i < n; i++){
        Node[i] = new node;
        Node[i]->data = i;
        Node[i]->lchild = NULL;
        Node[i]->rchild = NULL;
    }
    for(int i = 0; i < n; i++){
        int left, right;
        scanf("%d %d", &left, &right);
        if(left != -1) Node[i]->lchild = Node[left];
        if(right != -1) Node[i]->rchild = Node[right];
    }
    bool first = true;
    inorder(Node[0],first);
    printf("\n");
}