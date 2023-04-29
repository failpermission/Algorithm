#include<iostream>
#include<string>
using namespace std;
//先手函数，
string process(int N){
    if(N < 5) return (N == 0 || N == 2) ? "后手" : "先手";
    int base = 1;
    while(base <= N){
        if(process(N-base) == "后手") return "先手";//后手作为先手，先手会让后手结果为后手，也就是自己返回先手
        if(base > N/4) break;
        base*=4;
    }
    return "后手";
}
int main(){
    string str = "先手";
    cout << (str=="先手");
    return 0;
}
