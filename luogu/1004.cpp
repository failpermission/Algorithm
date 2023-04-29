#include<iostream>
#include<string.h>
using namespace std;
int map[10][10];
int f[10][10][10][10];
int N;
int dfs(int x1,int y1,int x2,int y2){//表示取完值后到(N,N)和(N,N)的最大距离
    if(f[x1][y1][x2][y2] != -1) return f[x1][y1][x2][y2];
    if(x1 == N && y1 == N && x2 == N && y2 == N) return 0;
    int M = 0;
    if(x1 < N && x2 < N){//两者都不在最后一行，都往下走
        M = max(M,dfs(x1+1,y1,x2+1,y2)+map[x1+1][y1]+map[x2+1][y2]-map[x1+1][y1]*(x1+1==x2+1&&y1==y2));       
    }
    if(x1 < N && y2 < N){//x1不在最后一行，y2不在最后一列
        M = max(M,dfs(x1+1,y1,x2,y2+1)+map[x1+1][y1]+map[x2][y2+1]-map[x1+1][y1]*(x1+1==x2&&y1==y2+1));
    }
    if(y1 < N && x2 < N){
        M = max(M,dfs(x1,y1+1,x2+1,y2)+map[x1][y1+1]+map[x2+1][y2]-map[x1][y1+1]*(x1==x2+1&&y1+1==y2));
    }
    if(y1 < N && y2 < N){
        M = max(M,dfs(x1,y1+1,x2,y2+1)+map[x1][y1+1]+map[x2][y2+1]-map[x1][y1+1]*(x1==x2&&y1+1==y2+1));
    }
    f[x1][y1][x2][y2] = M;
    return f[x1][y1][x2][y2];
}
int main(){
    cin >> N;
    while(1){
        int t1 = 0,t2 = 0,t3 = 0;
        cin >> t1 >> t2 >> t3;
        if(t1 == 0 && t2 == 0 && t3 == 0) break;
        map[t1][t2] = t3;
    }
    memset(f,-1,sizeof(f));
    cout << dfs(1,1,1,1)+map[1][1];
    return 0;
}