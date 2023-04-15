//背包问题的求解，与字符串的求解很像
#include<iostream>
#include<vector>
using namespace std;
int getMaxValues(vector<int>& weights,int* values,int alreadyWeight,int i,int bag){
    if(alreadyWeight > bag) return 0;
    if(i == weights.size()) return 0;
    return max(getMaxValues(weights,values,alreadyWeight,i+1,bag),values[i]+
        getMaxValues(weights,values,alreadyWeight+weights[i],i+1,bag));
}
int main(){

    return 0;
}
