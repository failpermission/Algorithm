//给定两个装苹果的袋子，分别能装6个和8个苹果，并且必须只能用这两种袋子，
//给定苹果数量，最少能用几个袋子装完？若不能装下，返回-1
#include<iostream>
using namespace std;
//方法一：从大到小枚举装8个苹果的袋子数量，如果剩下的能用装6个苹果的袋子装下，就是最少的
//显然奇数个不能装下
int process1(int N){
    if(N%2==1) return -1;
    int bag = N/8;
    int res = -1;
    for(int bag8 = bag;bag8 >= 0;bag8--){
        int rest = N-bag8*8;
        if(rest%6==0) {
            res = bag8+rest/6;
            break;
        }
    }
    return res;
}
int process2(int N){
    if(N%2==1) return -1;
    int bag = N/8;
    int res = -1;
    for(int bag8 = bag;bag8 >= 0;bag8--){
        int rest = N-bag8*8;
        if(rest > 24) return -1;
        if(rest%6==0) {
            res = bag8+rest/6;
            break;
        }
    }
    return res;
}
int main(){
    for(int n = 1;n <= 1000;n++) cout << (process1(n)==process2(n)) <<endl;
    return 0;
}