//假设给定一个数组和一个目标值aim，请求出在数组array中数字和等于aim的元素个数
//给出两个变量index,rest，表示从index开始自由选择，选择出rest的方式数，显然开始时index=0,rest=aim
#include<iostream>
#include<vector>
using namespace std;
//下面是暴力递归的解法，他是记忆化搜索和动态规划的基础
int process1(vector<int>& arr,int index,int rest){
    if(rest < 0) return -1;//表示没有组成方法
    if(rest == 0) return 0;//表示使用0枚硬币即可
    if(index == arr.size()) return -1;//表示没有组成方法
    int p1 = process1(arr,index+1,rest);//表示没有选择此硬币
    int p2 = process1(arr,index+1,rest-arr[index]);//表示选择此硬币
    if(p1 == -1 && p2 == -1) return -1;
    if(p2 == -1) return p1;
    if(p1 == -1) return p2+1;
    return min(p1,p2+1);
}
int solve1(vector<int>& arr,int aim){
    return process1(arr,0,aim);
}
//下面使用记忆化搜索的方法
int process2(vector<int>& arr,int index,int rest,vector<vector<int>>& dp){
    if(rest < 0) return -1;
    if(dp[index][rest] != -2) return dp[index][rest];
    if(rest == 0){
        dp[index][rest] = 0;
        return dp[index][rest];
    }
    if(index == arr.size()){
        dp[index][rest] = -1;
        return dp[index][rest];
    }
    int p1 = process2(arr,index+1,rest,dp);
    int p2 = process2(arr,index+1,rest-arr[index],dp);
    if(p1 == -1 && p2 == -1) dp[index][rest] = -1;
    else if(p2 == -1) dp[index][rest] = p1;
    else if(p1 == -1) dp[index][rest] = p2+1;
    else dp[index][rest] = min(p1,p2+1);
    return dp[index][rest];
 }
int solve2(vector<int>& arr,int aim){
    vector<vector<int>> dp(arr.size()+1,vector<int>(aim+1,-2));//需要将dp数组中的所有值首先初始化为-2
    return process2(arr,0,aim,dp);
}
//下面利用递归改编成动态规划
int solve3(vector<int>& arr,int aim){//只需返回dp[0][aim]
    int N = arr.size();
    vector<vector<int>> dp(N+1,vector<int>(aim+1));
    for(int row = 0;row <= N;row++) dp[row][0] = 0;
    for(int col = 1;col <= aim;col++) dp[N][col] = -1;
    for(int index = N-1;index >= 0;index--){
        for(int rest = 1;rest <= aim;rest++){
            int p1 = dp[index+1][rest];
            int p2 = -1;
            if(rest - arr[index] >= 0) p2 = dp[index+1][rest-arr[index]];
            if(p1 == -1 && p2 == -1) dp[index][rest] = -1;
            else{
                if(p2 == -1) dp[index][rest] = p1;
                else if(p1 == -1) dp[index][rest] = p2+1;
                else dp[index][rest] = min(p1,p2+1);
            }
        }
    }
    return dp[0][aim];
}
int main(){
    vector<int> arr(5);
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 100;
    arr[3] = 5;
    arr[4] = 1;
    cout << solve1(arr,7) << endl;
    cout << solve2(arr,7) << endl;
    cout << solve3(arr,7) << endl;
    return 0;
}