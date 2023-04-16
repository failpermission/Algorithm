//Kmp算法实现
#include<iostream>
#include<string>
using namespace std;
int* nextArray(string str){//实现函数得到str的next数组
    if(str.size() == 1){
        int* next = new int[1];
        next[0] = -1;
        return next;
    }
    int* next = new int[str.size()];
    next[0] = -1;
    next[1] = 0;
    int cn = 0;//表示i-1位置需要比较字符的位置以及最长前缀长度
    int i = 2;
    while(i < str.size()){
        if(str[i-1] = str[cn]) next[i++] = ++cn;
        else if(cn > 0) cn = next[cn];
        else next[i++] = 0;
    }
    return next;
}
int kmp(string s,string m){
    if(s.size() == 0 || m.size() == 0 || s.size() < m.size()) return -1;
    int i1 = 0;
    int i2 = 0;
    int* next = nextArray(m);
    while(i1 < s.size() && i2 < m.size()){
        if(s[i1] == m[i2]){
            i1++;
            i2++;
        }else if(next[i2] == -1) i1++;
        else{
            i2 = next[i2];
        }
    }
    free(next);
    return i2 == m.size() ? i1-i2 : -1;
}
int main(){
    string s = "abcdabcfdfabd";
    string m = "abcf";
    cout << kmp(s,m);
    return 0;
}