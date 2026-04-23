//time:2026.4.23
//idea:
//total = 0
//dfs(u, depth):
//    if (u is leaf node):
//        total += w[u] * depth
//        return
//    for each child v in children[u]:
//        dfs(v, depth + 1)
//main:
//    read n
//    read w[0..n-1]
//    read children list for each node
//    dfs(0, 0)
//    print total

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> children;
vector<int> w;
int total = 0;

void dfs(int u, int depth){
    if(children[u].empty()){
        total += w[u] * depth;
        return;
    }
    for(int v : children[u]){
        dfs(v, depth + 1);
    }
}

int main(){
    int n;
    cin >> n;
    w.resize(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    children.resize(n);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        children[i].resize(k);
        for(int j = 0; j < k; j++){
            cin >> children[i][j];
        }
    }
    dfs(0,0);
    cout << total << endl;
    return 0;
}