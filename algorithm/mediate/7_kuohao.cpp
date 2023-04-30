#include<iostream>
#include<string>
#include<string.h>
using namespace std;
//如果给定一个括号序列，怎么判断它是合法的？
//方法：1对于每个左括号，必须有右括号与之匹配，2所有括号必须匹配
bool process1(string s){
    int count = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '(') count++;
        else count--;
        if (count < 0) return false;//count < 0说明存在右括号没有与之匹配的左括号
    }
    if(count != 0) return false;
    return true;
}
//请计算出一个括号序列需要增加多少个括号才能使其成为合法括号序列
int priocess2(string s){
    int count = 0;
    int res = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '(') count++;
        else{
            if(count == 0) res++;//需要增加左括号，否则将成为不合法的括号序列
            else count--;
        }
    }
    res+=count;
    return res;
}
//给定一个括号序列，求出其中合法的括号序列的最长长度
//思路：遇到这种问题，一般需要枚举以每一个下标为右边界的长度，然后求出最长长度
//在枚举的过程中，通常可以使用dp，比如本题就可以将dp[i]设为以i为下标的最长连续合法子序列
int process3(string s){
    int n = s.size();
    int dp[n];
    memset(dp,0,sizeof(dp));
    int res = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == '(') dp[i] = 0;//以'('为结尾的最长序列一定是零
        else{//说明s[i]是')'
            int j = i-1-dp[i-1];//来到i-1的最长连续合法序列开头前一个位置
            if(s[j] == ')') dp[i] = 0;//不用考虑前面的内容，因为就算前面有能够匹配的位置，将会违反dp[i-1]的规则
            else{//说明s[j]=='('
                dp[i]+=(2+dp[i-1]);
                if(j > 0) dp[i]+=dp[j-1];//还要拼接上前面的最长合法序列
            }
        }
        res = max(res,dp[i]);
    }
    return res;
}
int main(){
    string s = "()((()()())";
    cout << process3(s);
    return 0;
}