//题目描述：给定两个整数集合，定义一种操作magic:将一个集合中的元素移动到另一个集合
//使得两个集合的平均值均增加，那么这种magic操作最多可以有几次？
//思路：将平均值较大的集合元素往平均值较小的集合中添加，这个元素需要大于小平均值并且小于大平均值
//贪心策略：从大平均值的集合中升序依次取出符合条件的元素，可以使得大平均值升高幅度大，小平均值升高幅度小
#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;
bool compare(int a,int b){return a < b;}
double getAverage(double sum,int len){return sum/len;}
int process(int* arr1,int len1,int* arr2,int len2){
    double sum1 = 0,sum2 = 0;
    for(int i = 0;i < len1;i++) sum1+=(double)arr1[i];
    for(int i = 0;i < len2;i++) sum2+=(double)arr2[i];
    if(getAverage(sum1,len1) == getAverage(sum2,len2)) return 0;
    int* arrMore = nullptr;
    int* arrLess = nullptr;
    double sumMore = 0;
    double sumLess = 0;
    if(getAverage(sum1,len1) > getAverage(sum2,len2)){
        arrMore = arr1;
        sumMore = sum1;
        arrLess = arr2;
        sumLess = sum2;
    }else{
        arrMore = arr2;
        sumMore = sum2;
        arrLess = arr1;
        sumLess = sum1;
    }
    sort(arrMore,arrMore+len1,compare);
    int moreSize = len1;
    int lessSize = len2;
    int ops = 0;
    unordered_set<int> s;
    for(int i = 0;i < len1;i++){
        double cur = (double)arrMore[i];
        if(cur > getAverage(sumLess,lessSize) && cur < getAverage(sumMore,moreSize)
        && s.find(arrMore[i]) == s.end()){
            sumMore-=cur;
            moreSize--;
            sumLess+=cur;
            lessSize++;
            ops++;
            s.insert(arrMore[i]);
        }
    }
    return ops;
}
int main(){

}