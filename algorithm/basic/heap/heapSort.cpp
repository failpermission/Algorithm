//该文件实现大根堆的创建以及调整
#include<iostream>
using namespace std;
void swap(int* arr,int i,int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
//大根堆的插入向上过滤操作
void heapInsert(int* arr,int index){//index是插入位置的下标
    while(arr[index] > arr[(index-1)/2]){//当index=0时，循环条件不满足，自动退出
        swap(arr,index,(index-1)/2);
        index = (index-1)/2;
    }
}
//大根堆从一个位置向下过滤操作
void heapify(int* arr,int index,int heapSize){
    int left = index*2+1;
    while(left < heapSize){
        int largest = (left+1)<heapSize && arr[left+1] > arr[left] ? left+1 : left;
        largest = arr[largest] > arr[index] ? largest : index;
        if(largest == index) break;
        swap(arr,index,largest);
        index = largest;
        left = 2*index+1;
    }
}
//实现堆排序
void heapSort(int* arr,int n){//n为数组的长度
    int heapSize = n;
    for(int i = 0;i < n;i++){//将数组调整为大根堆
        heapInsert(arr,i);
    }
    //可以根据下面操作实现创建堆
    // for(int i = n-1;i>=0;i--){
    //     heapify(arr,i,n);
    // }
    swap(arr,0,--heapSize);//将最大值放到最右侧
    while(heapSize > 0){
        heapify(arr,0,heapSize);//重新调整
        swap(arr,0,--heapSize);

    } 

}
int main(){
    int arr[10] = {2,7,8,3,4,5,19,90,4,5};
    for(int num : arr) cout << num <<" ";
    cout << endl;
    heapSort(arr,10);
    for(int num : arr) cout << num << " ";
    return 0;
}