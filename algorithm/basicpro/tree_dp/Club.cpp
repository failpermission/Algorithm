//树状dp，返回每个节点来与不来的最大值
#include<iostream>
#include<vector>
using namespace std;
//树节点
struct Employee{
    int happy;//快乐值
    vector<Employee> nexts;//直接下属节点
    Employee(int happy) : happy(happy){}
};
//返回值类型：来与不来两个值
struct ReturnType{
    int laiMaxhappy;
    int buMaxhappy;
    ReturnType(int laiMaxhappy,int buMaxhappy):laiMaxhappy(laiMaxhappy),buMaxhappy(buMaxhappy){}
};

//求解任意一个节点来与不来的快乐只
ReturnType* process(Employee& boss){
    if(boss.nexts.empty()) return new ReturnType(boss.happy,0);
    int laiMaxhappy = boss.happy;
    int buMaxhappy = 0;
    for(Employee e : boss.nexts){
        ReturnType* info = process(e);
        laiMaxhappy+=info->buMaxhappy;
        buMaxhappy+=max(info->buMaxhappy,info->laiMaxhappy);

        free(info);
    }

    return new ReturnType(laiMaxhappy,buMaxhappy);
}
int getMaxhappy(Employee& boss){
    ReturnType* info = process(boss);
    int res = max(info->laiMaxhappy,info->buMaxhappy);
    free(info);
    return res;
}
int main(){
    return 0;
}