//树状dp，求解一棵树的最大距离
#include<iostream>
using namespace std;
//设置树的节点
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val){}
};
//设置返回值类型
struct ReturnType{
    int maxDistance;
    int height;
    ReturnType(int maxDistance,int height):maxDistance(maxDistance),height(height){}
};
//对于任意一棵树求解出其最大距离
ReturnType* process(Node* x){
    if(!x) return new ReturnType(0,0);
    ReturnType* leftData = process(x->left);
    ReturnType* rightData = process(x->right);
    int leftDistance = leftData->maxDistance;
    int rightDistance = rightData->maxDistance;

    int maxDistance = max(leftData->height+rightData->height+1,max(leftDistance,rightDistance));
    int height = max(leftData->height,rightData->height)+1;

    free(leftData);
    free(rightData);
    return new ReturnType(maxDistance,height);

}

int main(){
    return 0;
}