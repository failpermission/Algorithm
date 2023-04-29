//假设有一个数组，里面分别代表硬币的面值，每种硬币有无限张，
//给定一个目标aim，那么硬币面值组成aim一共有多少种？
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
//暴力递归
//表示在index位置自由选择，还剩下rest面值需要选择，显然只要返回process(arr,0,aim)
int process1(vector<int>& arr,int index,int rest){
    if(index == arr.size()) return rest == 0 ? 1 : 0;
    int ways = 0;
    for(int zhang = 0;arr[index]*zhang <= rest;zhang++){//枚举在index位置的张数
        ways+=process1(arr,index+1,rest-arr[index]*zhang);
    }
    return ways;
}
//将暴力递归改成动态规划
int process2(vector<int>& arr,int aim){
    int N = arr.size();
    int res[N+1][aim+1];
    memset(res,0,sizeof(res));
    res[N][0] = 1;
    for(int index = N-1;index>=0;index--){
        for(int rest = 0;rest <= aim;rest++){
            for(int zhang = 0;arr[index]*zhang <= rest;zhang++){
                res[index][rest]+=res[index+1][rest-arr[index]*zhang];
            }
        }
    }
    return res[0][aim];
}
//process2中有三层循环，由于res[index][rest]的值总是包含res[index+1][rest]
//至于前面的部分，已经包含在res[index][rest-arr[index]]中
//因此res[index][rest] = res[index+1][rest]+res[index][rest-arr[index]]
int process3(vector<int>& arr,int aim){
    int N = arr.size();
    int res[N+1][aim+1];
    memset(res,0,sizeof(res));
    res[N][0] = 1;
    for(int index = N-1;index >= 0;index--){
        for(int rest = 0;rest <= aim;rest++){
            res[index][rest] = res[index+1][rest];
            if(rest-arr[index] >= 0) res[index][rest]+=res[index][rest-arr[index]];
        }
    }
    return res[0][aim];
}
int main(){
    vector<int> arr(2);
    arr[0] = 2;
    arr[1] = 3;
    cout << process1(arr,0,78) << endl;
    cout << process2(arr,78) << endl;
    cout << process3(arr,78);
    return 0;
}