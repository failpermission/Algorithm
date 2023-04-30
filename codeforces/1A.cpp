#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,a;
    cin >> n >> m >> a;
    cout << ((m+a-1)/a) * ((n+a-1)/a); 
    return 0;
}