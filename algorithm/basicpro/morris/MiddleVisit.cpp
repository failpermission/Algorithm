//使用Morris遍历实现中序遍历
//当该节点没有左子树时直接输出，有左子树时第二次到达该节点时输出
#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val){}
};
void middleVisit(Node* head){
    Node* cur = head;
    while(cur){
        Node* rightMost = cur->left;
        if(rightMost != nullptr){
            while(rightMost->right != nullptr && rightMost->right != cur){
                rightMost = rightMost->right;
            }
            if(rightMost->right == nullptr){
                rightMost->right = cur;
                cur = cur->left;
                continue;
            }else{
                rightMost->right = nullptr;
            }
        }
        cout << cur->val << endl;
        cur = cur->right;
    }
}
int main(){
    return 0;
}