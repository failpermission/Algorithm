//给定一个0和1组成的矩阵，返回一个最大边框是1的最大正方形长度
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int process1(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int res = 0;
    bool flag = false;
    //在一个矩形中枚举出所有的正方形，O(N^3):先枚举举行的每一个点是O(N^2)，在枚举矩形的长度
    for(int row = 0;row < n;row++){
        for(int col = 0;col < m;col++){
            for(int len = 1;len <= min(n-row,m-col);len++){//枚举矩形的边长
                flag = false;
                for(int i = row;i <= row+len-1;i++){
                    if(matrix[i][col] == 0 || matrix[i][col+len-1] == 0) {
                        flag = true;
                        break;
                    }
                }
                for(int i = col;i <= col+len-1;i++){
                    if(matrix[row][i] == 0 || matrix[row+len-1][i] == 0) {
                        flag = true;
                        break;
                    }
                }
                if(!flag) res = max(res,len);;
            }
        }
    }
    return res;
}
//在process1当中，显然是O(N^4)复杂度，这样的话显然复杂度过高，
//在检查正方形边框的算法当中，不需要使用循环，可以像第4题一样，使用额外的空间进行预处理以降低时间复杂度
//建立right矩阵，表示每个点包括本身在内向右有多少个连续的1
//建立down矩阵，表示每个点包括本身在内向下有多少个连续的1
int process2(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int right[n][m];
    int down[n][m];
    memset(right,0,sizeof(right));
    memset(down,0,sizeof(down));
    for(int row = 0;row < n;row++){
        for(int col = m-1;col >= 0;col--){
            if(matrix[row][col] == 0) right[row][col] = 0;
            else{
                if(col != m-1) right[row][col]+=right[row][col+1];
                right[row][col]+=1;
            }
        }
    }
    for(int col = 0;col < m;col++){
        for(int row = n-1;row >= 0;row--){
            if(matrix[row][col] == 0) down[row][col] = 0;
            else{
                if(row != n-1) down[row][col]+=down[row+1][col];
                down[row][col]+=1;
            }
        }
    }
    //矩阵创建完毕后。开始枚举正方形的顶点及其边长
    int res = 0;
    for(int row = 0;row < n;row++){
        for(int col = 0;col < m;col++){
            for(int len = 1;len <= min(n-row,m-col);len++){
                //左上顶点的向右和向下以及左下顶点的向右以及右上顶点的向下的连续1的长度要大于等于len
                if(right[row][col] >= len && down[row][col] >= len &&
                right[row+len-1][col] >= len && down[row][col+len-1] >= len) res = max(res,len);
            }
        }
    }
    return res;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> matrix[i][j];
        }
    }
    cout << process1(matrix) << endl;
    cout << process2(matrix) << endl;
    return 0;
}