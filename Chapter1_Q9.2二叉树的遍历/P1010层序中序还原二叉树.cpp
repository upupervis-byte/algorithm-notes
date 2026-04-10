//time 2026.4.6
//idea: 1.the first node in level-order is the root
//      2.divid the inorder sequence into left and right halves(根据中序分成左右两半)
//      3.extract corresponding nodes from level-order and recurse(递归)

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 50;

struct node{
    int val;
    int left, right;
}Node[maxn];

int nodeCount = 0;

int newNode(int val){
    Node[nodeCount].val = val;
    Node[nodeCount].left = -1;
    Node[nodeCount].right = -1;
    return nodeCount++;
}

int build(vector<int> level, vector<int> mid){
    if(level.empty() || mid.empty()) return -1;
    int rootVal = level[0];
    int rootIdx = newNode(rootVal);
    int pos = find(mid.begin(), mid.end(), rootVal) - mid.begin();
    vector<int> leftMid(mid.begin(), mid.begin() + pos);
    vector<int> rightMid(mid.begin()+pos+1, mid.end());
    vector<int> leftLevel, rightLevel;
    for(int v : level){
        if(find(leftMid.begin(), leftMid.end(), v) != leftMid.end()) leftLevel.push_back(v);
        if(find(rightMid.begin(), rightMid.end(), v) != rightMid.end()) rightLevel.push_back(v);
    }
    Node[rootIdx].left = build(leftLevel, leftMid);
    Node[rootIdx].right = build(rightLevel, rightMid);
    return rootIdx;
}

void preorder(int root, bool &first){
    if(root == -1) return;
    if(first){
        cout << Node[root].val;
        first = false;
    }
    else cout << " " << Node[root].val;
    preorder(Node[root].left, first);
    preorder(Node[root].right, first);
}

int main(){
    int n;
    scanf("%d",&n);
    vector<int> level(n);
    for(int i = 0; i < n; i++){
        cin >> level[i];
    }
    vector<int> mid(n);
    for(int i = 0; i < n; i++){
        cin >> mid[i];
    }
    int root = build(level, mid);
    bool first = true;
    preorder(root, first); 
}