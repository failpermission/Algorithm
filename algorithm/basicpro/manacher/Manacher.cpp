//实现求出字符串的最长回文子串算法
#include<iostream>
#include<string>
using namespace std;
string manacherString(string str){//实现将字符串转换为扩展字符串
    string res;
    res.resize(2*str.size()+1);
    int index = 0;
    for(int i = 0;i < res.size();i++){
        res[i] = (i & 1) == 0 ? '#' : str[index++];
    }
    return res;
}

//实现最长回文子串的算法
int manacher(string s){
    if(s.size() == 0) return 0;
    string str = manacherString(s);
    int* pArr = new int[str.size()];
    int C = -1;
    int R = -1;
    int maxNum = -1;
    for(int i = 0;i < str.size();i++){
        //先求出i的最少回文区域
        pArr[i] = R > i ? min(R-i,2*C-i) : 1;
        while(i+pArr[i] < str.size() && i-pArr[i] > -1){
            //下面实现外扩的情况只有两种
            //1.R <= i
            //2.对称点压线
            if(str[i+pArr[i]] == str[i-pArr[i]]) pArr[i]++;//实现外扩的情况只有两种
            else break;
        }
        if(i + pArr[i] > R){
            R = i+pArr[i];
            C = i;
        }
        maxNum = max(maxNum,pArr[i]);

    }

    free(pArr);
    return maxNum-1;
}
int main(){
   // string res = manacherString("abc");
    cout << manacher("abccbd");
   // free(res);
    return 0;
}