//找到两个节点的最近公共祖先
#include<iostream>
using namespace std;
//定义节点
struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val){}
};
//实现最近公共祖先的函数，注意体会树状dp的应用以及边界条件
Node* LCA(Node* node,Node* o1,Node* o2){
    if(node == nullptr || node == o1 || node == o2) return node;
    Node* left = LCA(node->left,o1,o2);
    Node* right = LCA(node->right,o1,o2);
    if(!left && !right) return node;
    return left!=nullptr ? left : right;
}
int main(){
    return 0;
}