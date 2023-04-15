//树状dp判断平衡树
#include<iostream>
using namespace std;
//设置树的结构体
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v){}
};
//设置返回值类型
struct ReturnType{
    int height;
    bool isBalance;
    ReturnType(int height,bool isBalance):height(height),isBalance(isBalance){}
};
//平衡树的判断
ReturnType* balanceTree(Node* node){
    if(!node) return new ReturnType(0,true);//空树是平衡树
    ReturnType* leftData = balanceTree(node->left);
    ReturnType* rightData = balanceTree(node->right);
    int height = max(leftData->height,rightData->height)+1;
    bool isBalance = leftData->isBalance && rightData->isBalance &&
        abs(leftData->height-rightData->height) < 2;
    free(rightData);
    free(leftData);
    return new ReturnType(height,isBalance);
}
int main(){
    
    return 0;
}