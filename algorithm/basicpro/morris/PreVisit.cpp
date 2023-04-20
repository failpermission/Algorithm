//使用Mirros遍历实现·1先序遍历
//当该节点没有左子树时，直接输出，当该节点有左子树时，第一次来到该节点输出
#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val){}
};
void preVisit(Node* head){
    Node* cur = head;
    while(cur){
        Node* rightMost = cur->left;
        if(!rightMost){
            while(rightMost->right != nullptr && rightMost->right != cur){
                rightMost = rightMost->right;
            }
            if(rightMost->right == nullptr){//第一次来到该节点
                cout << cur->val << endl;
                cur = cur->left;
                rightMost->right = cur;
                continue;
            }else{
                rightMost->right = nullptr;
            }
        }else{
            cout << cur->val << endl;
        }
        cur = cur->right;
    }
}
int main(){
    return 0;
}