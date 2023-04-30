#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin >> str;
    string s = "hello";
    int k = 0;
    for(int i = 0;i < str.size();i++){
        if(str[i] == s[k]) k++;
    }
    if(k == 5) cout << "YES";
    else cout << "NO";
    return 0;
}