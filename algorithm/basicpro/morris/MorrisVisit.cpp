//实现二叉树的Morris遍历，由左子树的根节点经过两次，没有左子树的根节点只遍历一次
//时间复杂度O(N)，空间复杂度D(1)
#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val):val(val){}
};
void Visit(Node* root){
    Node* cur = root;
    while(cur){
        Node* mostRight = cur->left;
        if(!mostRight){//有左子树的情况，找到左子树的最右节点
            while(mostRight->right != nullptr && mostRight->right != cur){
                mostRight = mostRight->right;
            }
            if(!mostRight->right){//第一次来到cur，接着继续往cur左边走
                mostRight->right = cur;
                cur = cur->left;
                continue;
            }else{//第二次来到cur，接着直接向cur右边走
                mostRight->right = nullptr;
            }
        }
        cur = cur->right;
    }
}
int main(){
    return 0;
}