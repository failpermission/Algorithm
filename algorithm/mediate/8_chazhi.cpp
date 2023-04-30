#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//给定一个数组，求出其中插值为k的有序对个数
int n;
int aim;
int process(unordered_set<int>& s,vector<int>& arr,int aim){
    int res = 0;
    for(int i = 0;i < arr.size();i++){
        if(s.find(arr[i]+aim) != s.end()) res++;
    }
    return res;
}
int main(){
    cin >> n >> aim;
    vector<int> arr(n);
    unordered_set<int> s;
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    cout << process(s,arr,aim);
    return 0;
}