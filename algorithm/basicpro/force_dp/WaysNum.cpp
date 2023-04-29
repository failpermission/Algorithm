//假设一个正整数N表示1,2...N个各自，有一个机器人最初在S位置，他要走到E位置，每次走K步
//请问一共有多少种走法？暴力递归->记忆化搜索->dp
#include<iostream>
using namespace std;
int f1(int N,int E,int cur,int rest){//这里N和E是不变的量,cur和rest是变量，根据变量改记忆化搜索和动态规划
    if(rest == 0) return cur == E ? 1 : 0;
    if(cur == 1) return f1(N,E,2,rest-1);
    if(cur == N) return f1(N,E,N-1,rest-1);
    return f1(N,E,cur-1,rest-1)+f1(N,E,cur+1,rest-1);
}
int walkWays1(int N,int S,int E,int K){
    return f1(N,E,S,K);
}
//为了避免递归过程中的重复操作，使用记忆化搜索，通过创建dp表，以空间换时间
int f2(int N,int E,int cur,int rest,int** dp){
    if(dp[rest][cur] != -1) return dp[rest][cur];//这里可以减少重复操作
    if(rest == 0) {
        dp[rest][cur] == cur == E ? 1 : 0;
        return dp[rest][cur];
    }
    if(cur == 1){
        dp[rest][cur] = f2(N,E,2,rest-1,dp);
    }else if(cur == N){
        dp[rest][cur] = f2(N,E,N-1,rest-1,dp);
    }else{
        dp[rest][cur] = f2(N,E,cur-1,rest-1,dp)+f2(N,E,cur+1,rest-1,dp);
    }
    return dp[rest][cur];
}
int walkWays2(int N,int S,int E,int K){
    int** dp = new int* [K+1];
    for(int i = 0;i <= K;i++) dp[i] = new int[N+1];
    for(int i = 0;i <= K;i++){
        for(int j = 0;j <= N;j++){
            dp[i][j] = -1;
        }
    }
    int res = f2(N,E,S,K,dp);
    free(dp);
    return res;
}
//使用动态规划
int walkWays3(int N,int S,int E,int K){
    int dp[K+1][N+1];
    for(int i = 1;i <= N;i++){
        if(i == E) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    for(int i = 1;i <= K;i++){
        for(int j = 1;j <= N;j++){
            if(j == 1) dp[i][j] = dp[i-1][2];
            else if(j == N) dp[i][j] = dp[i-1][N-1];
            else dp[i][j] = dp[i-1][j-1]+dp[i-1][j+1];
        }
    }
    return dp[K][S];
}
// void process(int** a,int n,int m){
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < m;j++){
//             a[i][j] = 2;
//         }
//     }
// }
// void a(){
//     int** res = new int*[2];
//     for(int i = 0;i < 2;i++) res[i] = new int[2];
//     process(res,2,2);
//     for(int i = 0;i < 2;i++){
//         for(int j = 0;j < 2;j++){
//             cout << res[i][j] << endl;
//         }
//     }
//     free(res);
// }

int main(){
    cout << walkWays1(5,2,4,4) << endl;
    cout << walkWays3(5,2,4,4) << endl;
    return 0;
}