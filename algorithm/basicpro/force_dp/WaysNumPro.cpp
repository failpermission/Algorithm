//这题是机器人的题目的推广，将以为数组推广成为二维数组
//假设有一个中国象棋的棋盘，10行9列，从(0,0)位置出发，到指定位置(x,y)走日字型一共setp步，那么一共有多少种走法
//从(0,0)走到(x,y)和从(x,y)走到(0,0)效果是一样的
#include<iostream>
#include<vector>
using namespace std;
//首先使用暴力递归，每次有八种走法
int process1(vector<vector<int>>& map,int x,int y,int step){
    if(x < 0 || x > 9 || y <0 || y > 8) return 0;
    if(step == 0) return x == 0 && y == 0 ? 1 : 0;
    return process1(map,x-1,y-2,step-1)+
    process1(map,x-2,y-1,step-1)+
    process1(map,x-1,y+2,step-1)+
    process1(map,x-2,y+1,step-1)+
    process1(map,x+1,y-2,step-1)+
    process1(map,x+2,y-1,step-1)+
    process1(map,x+1,y+2,step-1)+
    process1(map,x+2,y+1,step-1);
}
//将暴力递归改成动态规划表
int getVal(vector<vector<vector<int>>>& dp,int k,int m,int n){
    if(m < 0 || m > 9 || n < 0 || n > 8) return 0;
    return dp[k][m][n];
}
int process2(vector<vector<int>>& map,int x,int y,int step){
    int m = map.size();//行
    int n = map[0].size();//列
    vector<vector<vector<int>>> dp(step+1,vector<vector<int>>(m,vector<int>(n)));
   // int dp[step+1][m][n];
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            dp[0][i][j] = x == 0 && y == 0 ? 1 : 0;
        }
    }
    for(int k = 1;k <= step;k++){
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                dp[k][i][j] = getVal(dp,k-1,m-1,n-2)+
                getVal(dp,k-1,m-2,n-1)+
                getVal(dp,k-1,m-1,n+2)+
                getVal(dp,k-1,m-2,n+1)+
                getVal(dp,k-1,m+1,n-2)+
                getVal(dp,k-1,m+2,n-1)+
                getVal(dp,k-1,m+1,n+2)+
                getVal(dp,k-1,m+2,n+1);
            }
        }
    }
    return dp[step][x][y];
}
int main(){
    vector<vector<int>> map(10,vector<int>(9));
    cout << process1(map,2,1,1) << endl;
    cout << process2(map,2,1,1) << endl;
    return 0;
}