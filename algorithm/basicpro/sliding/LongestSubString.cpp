//使用滑动窗口解决无重复最长子串的长度
#include<bits/stdc++.h>
using namespace std;
int longestSubString(string s){
    if(s.size() == 0) return 0;
    int rk = -1;//右指针位置
    unordered_set<char> occ;//统计加入的字符是否重复
    int n = s.size();
    int res = 1;
    for(int i = 0;i < n;i++){
        if(i != 0){
            occ.erase(s[i-1]);//表示左指针右移
        }
        while(rk+1 < n && occ.count(s[rk+1]) != 0){
            occ.insert(s[rk+1]);
            rk++;
        }
        res = max(res,rk-i+1);
    }
    return res;
}
int main(){

}