#include<iostream>
#include<vector>
using namespace std;
//实现并查集的按秩合并
class Union{
private:
    vector<int> father;//向上找的最顶节点
    vector<int> rank;//秩
public:
    void unionInit(int n){
        father.resize(n);
        for(int i = 0;i < n;i++) father[i] = i;
        rank.resize(n,1);
    }
    int unionFind(int i){
        if(i == father[i]) return i;
        return unionFind(father[i]);
    }
    void merge(int a,int b){
        int rootA = unionFind(a);
        int rootB = unionFind(b);
        if(rank[rootA] <= rank[rootB]) father[rootA] = rootB;
        else father[rootB] = rootA;
        if(rank[rootA] == rank[rootB]) rank[rootB]++;
    }
};


int main(){
    return 0;
}