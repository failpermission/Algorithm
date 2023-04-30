#include<iostream>
#include<algorithm>
using namespace std;
int num[5];
int compare(int a,int b) {return a < b;}
int main(){
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        num[arr[i]]++;
    }
    int res = n;
    res-=min(num[1],num[3]);
    num[1]-=min(num[1],num[3]);
    res-=(num[2]/2);
    num[2]-=(num[2]/2*2);
    if(num[1] > 0 && num[2] > 0){
        res-=1;
        num[2] = 0;
        num[1]-=1;
    }
    if(num[1] > 0) res-=(num[1]+4-1)/4;
    cout << res;
    // sort(arr,arr+n,compare);
    // int res = n;
    // int i = 0;
    // int j = n-1;
    // while(i < j){
    //     if(arr[i] == 1 && arr[j] == 3){
    //         res--;
    //         i++;
    //         j--;
    //         continue;
    //     }
    //     if(arr[j] <= 2) break;
    //     j--;
    // }
    // while(i < j){
    //     if(arr[j] == 2 && arr[j-1]==2){
    //         res--;
    //         j-=2;
    //     }
    // }
    // if(i < j && arr[i] == 1 && arr[j] == 2){
    //     res--;
    //     i++;
    //     j--;
    // }
    // if(i < j) res-=((j-i+4)/4);
    // cout << res;
    return 0;
}