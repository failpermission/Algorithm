//求出一个字符串的全排列，并且去重
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void swap(string& arr,int i,int j){
    char tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void process(string s,int i,vector<string>& res){//i表示当前需要交换的位置
    if(i == s.size()) res.push_back(s);
    bool vis[26] = {0};
    for(int j = i;j < s.size();j++){
        if(!vis[s[j]-'a']){
            vis[s[j]-'a'] = true;
            swap(s,i,j);
            process(s,i+1,res);
            swap(s,i,j);
        }
    }
}
int main(){
    string s = "abc";
    vector<string> res;
    process(s,0,res);
    for(string val : res) cout << val << endl;
    return 0;
}