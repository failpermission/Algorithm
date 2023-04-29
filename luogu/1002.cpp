
#include<iostream>
using namespace std;
int x,y,m,n;
int map[25][25];
int res[25][25];
int dx[9] = {0,-1,-2,1,2,-1,-2,1,2};
int dy[9] = {0,-2,-1,2,1,2,1,-2,-1};
int process1(int x,int y){
    if(x == 0 && y == 0) return 1;
    if(map[x][y] || x < 0 || y < 0) return 0;
    return process1(x-1,y)+process1(x,y-1);
}
int getVal(int x,int y){
    if(map[x][y] || x < 0 || y < 0) return 0;
    return res[x][y];
}
int process2(int x,int y){
    for(int i = 0;i <= x;i++){
        for(int j = 0;j <= y;j++){
            if(i == 0 && j == 0) res[i][j] = 1;
            else{
                res[i][j] = getVal(i-1,j)+getVal(i,j-1);
            }
        }
    }
    return res[x][y];
}
int main(){
    cin >> x >> y >> m >> n;
    for(int i = 0;i < 9;i++)map[m+dx[i]][n+dy[i]] = 1;
    cout << process1(x,y) << endl;
    cout <<process2(x,y) << endl;
    return 0;
}