//使用Morris遍历实现对二叉搜索树的判断
#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val){}
};
bool isBST(Node* head){
    if(!head) return true;
    Node* cur = head;
    int preNum = INT_MIN;
    while(cur){
        Node* rightMost = cur->left;
        if(rightMost != nullptr){
            while(rightMost->right != nullptr && rightMost->right != cur){
                rightMost = rightMost->right;
            }
            if(!rightMost->right){//第一次来到cur节点
                rightMost->right = cur;
                cur = cur->left;
                continue;
            }else{//第二次来到cur节点
                rightMost->right = nullptr;
            }
        }
        //来到这个地方时，要么是节点没有左子树，要么是第二次走过cur节点，接下来需要走cur右节点
        if(cur->val <= preNum) return false;
        preNum = cur->val;
        cur = cur->right;
    }
}

int main(){

}
