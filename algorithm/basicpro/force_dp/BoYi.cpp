//给定一个L-R的正整数数组，甲先手拿，乙后手拿，求出最后拿到的最大值
#include<iostream>
#include<vector>
using namespace std;
//先手函数，指的是在L-R上找出先手最大值
int s(int* arr,int L,int R);
int f(int* arr,int L,int R){
    if(L == R) return arr[L];
    return max(arr[L]+s(arr,L+1,R),arr[R]+s(arr,L,R-1));
}

//后手函数，指的是在L-R上后手最大值，后手指的是当前值将要被对面拿走
int s(int* arr,int L,int R){
    if(L == R) return 0;
    return min(f(arr,L,R-1),f(arr,L+1,R));
}
//将上述函数改成动态规划，其中变量是L和R，注意L和R的范围，其中L <= R恒成立
int process(int* arr,int length){
    if(length < 1) return -1;
    int dp_f[length][length];//先手二维表
    int dp_s[length][length];//后手二维表
    for(int i = 0;i <= length-1;i++){
        dp_f[i][i] = arr[i];
        dp_s[i][i] = 0;
    }
    for(int L = length-2;L>=0;L--){
        for(int R = L+1;R<=length-1;R++){
            dp_f[L][R] = max(arr[L]+dp_s[L+1][R],arr[R]+dp_s[L][R-1]);
            dp_s[L][R] = min(dp_f[L][R-1],dp_f[L+1][R]);
        }
    }
    return max(dp_f[0][length-1],dp_s[0][length-1]);
}
int main(){
    int arr[8] = {100,200,100,8,1000,345,6,2};
    cout << max(f(arr,0,7),s(arr,0,7)) << endl;
    cout << process(arr,8) << endl;
    return 0;
}