#include<iostream>
#include<string>
#include<string.h>
using namespace std;
//给定一个颜色数组"RGRRG"，将其重新染色，使得R全部在左边，G全部在右边，最少需要·染色多少次？
int process1(string s){
    int N = s.size();
    //枚举左侧长度
    int res = N;
    int k = 0;
    for(int L = 0;L <= N;L++){
        k = 0;
        if(L == 0){//统计整个字符串一共有几个R，将R改为G
            for(int i = 0;i <= N-1;i++){
                if(s[i] == 'R') k++;
            }
            res = min(res,k);
        }else if(L == N){//统计整个字符串一共有几个G，将G改为·1R
            for(int i = 0;i <= N-1;i++){
                if(s[i] == 'G')k++;
            }
            res = min(res,k);
        }else{//统计[0,L-1]有多少个G,[L,N-1]有多少个R
            for(int i = 0;i <= L-1;i++){
                if(s[i] == 'G') k++;
            }
            for(int i = L;i <= N-1;i++){
                if(s[i] == 'R') k++;
            }
            res = min(res,k);
        }
    }
    return res;
}
int process2(string s){
    int N = s.size();
    //创建一个长度为N的整型数组，从左侧枚举统计每个位置左侧一共有多少个G
    int left[N+1];
    memset(left,0,sizeof(left));
    for(int i = 0;i <= N-1;i++){
        if(i != 0) left[i]+=left[i-1];
        if(s[i] == 'G') left[i]++;
    }
    //创建一个长度为N的整型数组，从右侧枚举，统计每个位置右侧一共有多少个G
    int right[N+1];
    memset(right,0,sizeof(right));
    for(int i = N-1;i>=0;i--){
        if(i != N-1) right[i]+=right[i+1];
        if(s[i] == 'R') right[i]++;
    }
    //枚举每次来到的位置，直接得出左侧多少个G，右侧多少个R
    int res = N;
    for(int i = 0;i <= N-1;i++){
        res = min(res,(left[i]+right[i+1]));
        //if(left[i]=='R') res--;
    }
    return res;
}
int main(){
    string s = "RGRRGGRGRRGRGRGGGRRRGGRRGRGRGRRGRGGGRR";
    cout << process1(s) << endl;
    cout << process2(s) << endl;
    return 0;
}