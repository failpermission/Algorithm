//树状dp，判断一棵树是否是二叉搜索树
#include<iostream>
using namespace std;
//定义树节点
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val):val(val){};
};
//定义返回值类型
struct ReturnType{
    int maxNum;
    int minNum;
    bool isSearch;
    ReturnType(int maxNum,int minNum,bool isSearch):maxNum(maxNum),minNum(minNum),isSearch(isSearch){}
};
//实现判断二叉搜索树的函数
ReturnType* searchTree(Node* node){
    if(!node) return nullptr;
    ReturnType* leftData = searchTree(node->left);
    ReturnType* rightData = searchTree(node->right);
    int maxNum = node->val;
    int minNum = node->val;
    if(leftData){
        maxNum = max(maxNum,leftData->maxNum);
        minNum = min(minNum,leftData->minNum);
    }
    if(rightData){
        maxNum = max(maxNum,rightData->maxNum);
        minNum = min(minNum,rightData->minNum);
    }
    bool isSearch = true;
    if(!leftData && (node->val <= leftData->maxNum)) isSearch = false;
    if(!rightData && (node->val >= rightData->minNum)) isSearch = false;
    free(leftData);
    free(rightData);
    return new ReturnType(maxNum,minNum,isSearch);
}
int main(){
    return 0;
}