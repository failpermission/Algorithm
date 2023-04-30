//给定一个二叉树的节点数，一共能组成多少种二叉树结构
#include<iostream>
using namespace std;
//每一棵二叉树都有左子树和右子树，相比于根节点来说，只需要得出左子树的二叉树种类，再乘以
//右子树的二叉树种类，其中左子树的节点数量需要枚举
int process1(int n){
    if(n < 0) return 0;
    if(n == 0) return 1;//空树
    if(n == 1) return 1;
    if(n == 2) return 2;
    //枚举左子树的节点个数
    int res = 0;
    for(int i = 0;i <= n-1;i++){
        int j = n-1-i;//右子树的数量
        int left = process1(i);//左子树种类数
        int right = process1(j);
        res+=left*right;
    }
    return res;
}
//很明显，上述的递归行为可以改成动态规划
int process2(int n){
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int k = 3;k <= n;k++){
        int res = 0;
        for(int i = 0;i <= k-1;i++){
            int j = k-i-1;
            res+=dp[i]*dp[j];
        }
        dp[k] = res;
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << process1(n) << endl;
    cout << process2(n) << endl;
    return 0;
}