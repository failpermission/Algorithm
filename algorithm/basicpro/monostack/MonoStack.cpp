#include<bits/stdc++.h>
using namespace std;
//使用单调队列求出一个数组中每个元素左边和右边最靠近的大于当前值的下标
struct node{
    int left;
    int right;
};
node* monoStack(vector<int> arr){
    int n = arr.size();
    node* res = new node[n];
    stack<int> s;
    for(int i = 0;i < n;i++){
        while(!s.empty() && arr[i] > arr[s.top()]){
            int tmp = s.top();
            s.pop();
            res[tmp].left = s.empty() ?  -1 : s.top();
            res[tmp].right = i;
        }
        s.push(i);
    }
    while(!s.empty()){
        int x = s.top();
        s.pop();
        res[x].right = -1;
        res[x].left = s.empty() ? -1 : s.top();
    }
    return res;
}
int main(){

}