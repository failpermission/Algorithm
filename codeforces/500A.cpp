#include<iostream>
#include<string.h>
using namespace std;
int n,aim;
int arr[30005];
bool process(int k){
    if(arr[k] == aim) return true;
    if(arr[k] > aim || arr[k] == -1) return false;
    return process(arr[k]);
}
int main(){
    cin >> n >> aim;
    memset(arr,-1,sizeof(arr));
    int t;
    for(int i = 1;i <= n-1;i++){
        cin >> t;
        arr[i] = i+t;
    }
    if(process(1)) cout << "YES";
    else cout << "NO";
    return 0;
}