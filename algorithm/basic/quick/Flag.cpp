#include<iostream>
using namespace std;
//实现交换函数
void myswap(int* arr,int i,int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
//将小于等于num的数放左边，大于num的数放右边
void process1(int* arr,int n,int num){
    int less = -1;
    for(int i = 0;i < n;i++){
        if(arr[i] <= num) myswap(arr,i,++less);
    }
}
//将小于num的数放左边，等于num的数放中间，大于num的数放右边
void process2(int* arr,int n,int num){
    int less = -1;//小于区的右边界
    int more = n;//大于区的左边界
    int i = 0;
    while(i < more){
        if(arr[i] < num) myswap(arr,++less,i++);
        else if(arr[i] == num) i++;
        else myswap(arr,i,--more);
    }
}
int main(){
    int arr[10] = {2,6,7,8,3,2,1,9,0,2};
    for(int i = 0;i < 10;i++) cout << arr[i] <<" ";
    cout << endl;
    process2(arr,10,6);
    for(int i = 0;i < 10;i++) cout << arr[i] <<" ";
    cout << endl;
    return 0;
}