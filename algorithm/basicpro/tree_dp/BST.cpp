#include<iostream>
//使用动态的方式判断一棵树是否是二叉搜索树
using namespace std;
int preVal = INT_MIN;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val){}
};

bool isBST(Node* head){
    if(!head) return true;
    if(isBST(head->left)) return false;
    if(head->val <= preVal) return false;
    else preVal = head->val;
    return isBST(head->right);
}
int main(){
    return 0;
}