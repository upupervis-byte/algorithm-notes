//time: 2026.4.11
//idea: 

#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 50;

struct node{
    vector<int> child;  // ✅ 改成这样
}Node[maxn];

void PreOrder(int root, bool &first){
    // 注意：题目保证树连通且根为0，root不会为-1，所以这行可以省略
    // if(root == -1) return;
    
    if(!first) printf(" ");
    else first = false;
    printf("%d", root);
    
    for(int i = 0; i < Node[root].child.size(); i++){
        PreOrder(Node[root].child[i], first);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            int child;
            scanf("%d", &child);
            Node[i].child.push_back(child);
        }
    }
    bool first = true;
    PreOrder(0, first);
    return 0;
}