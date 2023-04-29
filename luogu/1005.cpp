#include<iostream>
using namespace std;
int map[85][85];
int n,m;
int process(int n,int L,int R){//表示第n行在区间[L,R]内第k次选择的最大值
    if(L == R) return (map[n][L] << (m-R+L));
    //每次都有两种选择，选择左边或者选择右边
    int left = (1<<(m-R+L))*(map[n][L])+process(n,L+1,R);
    int right = (1<<(m-R+L))*(map[n][R])+process(n,L,R-1);
    return max(left,right);
}
//上面的递归可以使用动态规划二维表
// int process1(int n,int L,int R){
//     int dp[m+1][m+1];
//     for(int i = 1;i <= m;i++) dp[i][i] = map[n][i] << (m-R+L);
//     for(int l = m-1;l >= 1;l--){
//         for(int r = l+1;r <= m;r++){
//             dp[l][r] = max(((1<<(m-r+l))*(map[n][l])+dp[l+1][r]),((1<<(m-r+l))*(map[n][r])+dp[l][r-1]));
//         }
//     }
//     return dp[1][m];
// }
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> map[i][j];
        }
    }
    int res = 0;
    for(int i = 1;i <= n;i++){
        res+=process(i,1,m);
    }
    cout << res;
    return 0;
}