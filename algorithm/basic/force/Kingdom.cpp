//n皇后问题求解
#include<iostream>
using namespace std;

bool check(int* record,int i,int j){
    for(int k = 0;k < i;k++){
        if(record[k] == j || abs(i-k) == abs(j-record[k])) return false; 
    }
    return true;
}
int process(int* record,int i,int n){
    if(i == n) return 1;
    int res = 0;
    for(int j = 0;j < n;j++){
        if(check(record,i,j)){
            record[i] = j;
            res+=process(record,i+1,n);
        }
    }
    return res;
}
int num(int n){
    if(n == 0) return 0;
    int* record = new int[n];
    int res = process(record,0,n);
    free(record);
    return res;
    
    
}
int main(){
    return 0;
}