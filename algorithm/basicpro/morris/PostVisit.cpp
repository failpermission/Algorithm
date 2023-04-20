//利用Morris遍历实现二叉树的后序遍历
//当第二次来到cur 节点时，逆序打印该节点的左子树的右边界，最后打印整棵树的右边界
#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val){}
};
//实现函数，将一棵树的右边界反转
Node* reverse(Node* from){
    Node* pre = nullptr;
    Node* next;
    while(from){
        next = from->right;
        from->right = pre;
        pre = from;
        from = next;
    }
    return pre;
}

//实现函数，打印一棵树的右边界
void printEdge(Node* x){
    Node* tail = reverse(x);
    Node* cur = tail;
    while(cur){
        cout << cur->val << endl;
        cur = cur->right;
    }
    reverse(tail);
}

//实现后序遍历
void PostVisit(Node* head){
    Node* cur = head;
    while(cur){
        Node* rightMost = head->left;
        if(!rightMost){
            while(rightMost->right != nullptr && rightMost->right != cur){
                rightMost = rightMost->right;
            }
            if(rightMost == nullptr){
                rightMost->right = cur;
                cur = cur->left;
                continue;
            }else{
                rightMost->right = nullptr;
                printEdge(cur->left);

            }
        }
        cur = cur->right;
    }
    printEdge(head);
}
int main(){
    return 0;
}