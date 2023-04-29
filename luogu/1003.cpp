#include<iostream>
using namespace std;
int n;
const int MAXN = 10000+5;
int a[MAXN],b[MAXN],g[MAXN],k[MAXN];
int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    int x,y;
    int res = -1;
    cin >> x >>y;
    for(int i = 0;i < n;i++){
        if(x >= a[i] && y >= b[i] && x <= a[i]+g[i] && y <= b[i]+k[i]){
            res = i+1;
        }
    }
    cout << res;
    return 0;
}