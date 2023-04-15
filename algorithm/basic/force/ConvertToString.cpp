//实现数字字符串向小写字母字符串的转换，类似于dp
#include<iostream>
#include<string>
using namespace std;
int process(string str,int i){//代表前i个位置已经决定好了，能转换为字符串的个数
    if(i == str.size()) return 1;
    if(str[i] == '0') return 0;
    if(str[i] == '1'){
        int res = process(str,i+1);
        if(i+1 < str.size()) res+=process(str,i+2);
        return res;
    }
    if(str[i] == '2'){
        int res = process(str,i+1);
        if(i+1<str.size() && str[i+1]>='0' && str[i+1]<='6'){
            res+=process(str,i+2);
        }
        return res;
    }
    return process(str,i+1);
}
int main(){
    string str = "1899";
    cout << process(str,0);
    return 0;
}