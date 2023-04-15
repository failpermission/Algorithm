//快速排序实现
#include<iostream>
using namespace std;

void myswap(int* arr,int i,int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int* partition(int* arr,int L,int R){
    int less = L-1;
    int more = R;
    int* p = new int[2];//存储等于arr[R]的下标
    while(L < more){
        if(arr[L] < arr[R]) myswap(arr,++less,L++);
        else if(arr[L] == arr[R]) L++;
        else myswap(arr,L,--more);
    }
    myswap(arr,more,R);
    p[0] = less+1;
    p[1] = more;
    return p;
}
void quickSort(int* arr,int L,int R){
    int index = L+((rand())%(R-L+1));//随机取一个下标,将arr[index]放到R位置上
    myswap(arr,index,R);//将arr[index]作为中轴，将小于arr[index]放左边，大于arr[index]放右边
    int* p = partition(arr,L,R);
    quickSort(arr,L,p[0]-1);
    quickSort(arr,p[1]+1,R);
    free(p);
}


int main(){
    int arr[10] = {3,4,5,6,1,2,9,8,7,10};
    for(int i = 0;i < 10;i++) cout << arr[i] <<" ";
    cout << endl;
    quickSort(arr,0,9);
    for(int i = 0;i < 10;i++) cout << arr[i] <<" ";
    return 0;
}