//在二叉树有指向parenr的指针时，寻找中序遍历的后继节点
#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int val):val(val){}
};

Node* getLeftMost(Node* node){//寻找一个节点的最左节点
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

//实现目标函数
Node* Successor(Node* node){
    if(node == nullptr) return nullptr;
    if(node->right != nullptr){//返回右子树最左节点
        return getLeftMost(node->right);
    }
    else{//找到node作为parent左子树的parent
        Node* parent = node->parent;
        while(parent && parent->left != node){
            node = parent;
            parent = node->parent;
        }
        return parent;
    }
}
int main(){
    return 0;
}