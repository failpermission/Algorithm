#include<iostream>
#include<string>
using namespace std;
bool judge(char& ch){
    if(ch == 'a' || ch == 'A' || ch == 'o' || ch == 'O' || ch == 'e' || ch == 'E'
    || ch == 'y' || ch == 'Y' || ch == 'i' || ch == 'I' || ch == 'u' || ch == 'U')
        return true;
    return false;
}
int main(){
    string s1;
    cin >> s1;
    int n1 = s1.size();
    for(int i = 0;i < s1.size();i++){
        if(judge(s1[i])) n1--;
    }
    int n2 = 2*n1;
    int k = n2-1;
    string s2(n2,'0');
    for(int i = s1.size()-1;i >= 0;i--){
        if(judge(s1[i])) continue;
        if(s1[i] >= 65 && s1[i] <= 90) s1[i]+=32;
        s2[k--] = s1[i];
        s2[k--] = '.';
    }
    cout << s2;
    return 0;
}