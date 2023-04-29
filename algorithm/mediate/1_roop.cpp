//给定一个数组，数组中的数分别代表数轴上的点，有一个固定长度的绳子。最多能覆盖几个点？
#include<iostream>
#include<vector>
using namespace std;
//方法一：二分，分别统计以每个点为绳子右端点能覆盖点的个数，再计算出最大值
//需要找到第一个大于等于arr[i]-length的点下标

//实现函数，在0-R范围内找到第一个大于等于目标值的下标 O(NlogN)
int getIndex(vector<int>& arr,int R,int aim){
    int res = R;
    int l = 0;
    int r = R;
    while(l <= r){
        int mid = l+((r-l)>>1);
        if(arr[mid] >= aim){
            res = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return res;
}
int process1(vector<int>& arr,int length){
    if(!arr.size()) return 0;
    int res = 1;
    for(int index = 0;index < arr.size();index++){//枚举绳子的每个右端点
        int aim = arr[index]-length;
        int leftIndex = getIndex(arr,index,aim);
        res = max(res,index-leftIndex+1);
    }
    return res;
}
//考虑使用滑动窗口解决问题，思路：
//1.枚举绳子左端点，以绳子长度length为窗口长度，找到绳子右端点能走到最远的数组下标，计算出长度
//2.绳子左端右移一个下标，计算下一个长度，这样左右端不后退，O(N)
int process2(vector<int>& arr,int length){
    int left = 0;//窗口做下标
    int right = -1;//窗口右下标
    int res = 1;
    while(right+1 < arr.size()){
        while(right+1 < arr.size() && length >= arr[right+1]-arr[left]) right++; 
        res = max(res,right-left+1);
        left++;
    }
    return res;
}
int main(){
    vector<int> arr(5);
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 7;
    arr[3] = 8;
    arr[4] = 12;
    cout << process1(arr,3) << endl;
    cout << process1(arr,4) << endl;
    cout << process1(arr,5) << endl;
    cout << process2(arr,3) << endl;
    cout << process2(arr,4) << endl;
    cout << process2(arr,5) << endl;
    return 0;
}