#include<iostream>
using namespace std;
//使用递归求一个数组最大值
int getMax(int* arr,int L,int R){
    if(L == R) return arr[L];
    int mid = L+((R-L)>>1);
    int leftMax = getMax(arr,L,mid);
    int rightMax = getMax(arr,mid+1,R);
    return max(leftMax,rightMax);
}

void merge(int* arr,int L,int mid,int R){//实现合并函数
    int* help = new int[R-L+1];
    int l = L;
    int r = mid+1;
    int i = 0;
    while(l <= mid && r <= R){
        help[i++] = arr[l] <= arr[r] ? arr[l++] : arr[r++];
    }
    while(l <= mid) help[i++] = arr[l++];
    while(r <= R) help[i++] = arr[r++];
    for(i = 0;i < (R-L+1);i++) arr[i+L] = help[i];
    free(help);
}
//实现归并排序
void mergeSort(int* arr,int L,int R){
    if(L == R) return;
    int mid = L+((R-L)>>1);
    mergeSort(arr,L,mid);
    mergeSort(arr,mid+1,R);
    merge(arr,L,mid,R);
}

//实现求出小和的process函数
int process(int* arr,int L,int M,int R){
    int p1 = L;
    int p2 = M+1;
    int* help = new int[R-L+1];
    int res = 0;
    int i = 0;
    while(p1 <= M && p2 <= R){
        res+=arr[p1] < arr[p2] ? arr[p1] * (R-p2+1) : 0;
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while(p1 <= M) help[i++] = arr[p1++];
    while(p2 <= R) help[i++] = arr[p2++];
    for(i = 0;i < (R-L+1);i++) arr[i+L] = help[i];
    return res;
}
//实现小和，将一个数成上一定次数，次数为后面大于该数的个数
int getSmallsum(int* arr,int L,int R){
    if(L == R) return 0;
    int mid = L+((R-L) >> 1);
    int sum1 = getSmallsum(arr,L,mid);
    int sum2 = getSmallsum(arr,mid+1,R);
    return sum1+sum2+process(arr,L,mid,R);
}
int main(){
    int arr[10] = {1,6,5,7,90,4,9,3,4,5};
    for(int num : arr) cout << num <<" ";
    cout << endl;
    mergeSort(arr,0,9);
    for(int num : arr) cout << num <<" ";
    cout << endl;
    int arr1[3] = {1,2,3};
    cout << getSmallsum(arr1,0,2);

    return 0;
}