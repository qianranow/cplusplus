//
// Created by qianranow on 2022/2/25.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
using namespace std;

#define SALE_DEPATMENT 1 //销售部门
#define DEVELOP_DEPATMENT 2 //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门

class Worker
{
public:
    string name;
    int age;
    int salary;
};

void CreateWorker(vector<Worker> &vWorker)
{
    srand((unsigned int)time(NULL));
    string setName = "ABCDE";
    for (int i = 0; i < 5; ++i) {
        Worker worker;
        worker.name = "员工";
        worker.name += setName[i];
        worker.age = rand() % 30 + 30;
        worker.salary = rand() % 20000 + 20000;
        vWorker.push_back(worker);
    }
}

void WokerByGroup(vector<Worker> &vWorker, multimap<int, Worker> &mWorkers)
{
    //遍历员工
    for (vector<Worker>::iterator it = vWorker.begin();it!=vWorker.end();++it)
    {
        //生成部门编号
        int id = rand() % 3 + 1;
        //员工保存到mWorkers
        mWorkers.insert(make_pair(id, *it));
    }
}

void myGroup(multimap<int, Worker> &mWorkers, int id)
{
    //查询id
   multimap<int, Worker>::iterator it = mWorkers.find(id);
    //查询部门人数
    int mcount = mWorkers.count(id);
    //临时变量
    int index = 0;
    for (;it!=mWorkers.end()&&index<mcount; ++it, ++index)
    {
        cout << "name:" << it->second.name << "age" << it->second.age << "salary" << it->second.salary << endl;
    }
}

void PrintWoker(multimap<int, Worker> &mWorkers)
{
    cout << "财务部门员工信息如下：" << endl;
    myGroup(mWorkers, FINACIAL_DEPATMENT);
    cout << "研发部门员工信息如下：" << endl;
    myGroup(mWorkers, DEVELOP_DEPATMENT);
    cout << "销售部门员工信息如下：" << endl;
    myGroup(mWorkers, SALE_DEPATMENT);
}

void test()
{
    //保存未分组的员工信息
    vector<Worker> vWorker;
    //保存分组后员工的信息
    multimap<int, Worker> mWorkers;
    //创建员工
    CreateWorker(vWorker);
    //分组，把分好组的员工放入mWorkers
    WokerByGroup(vWorker, mWorkers);
    //打印员工信息
    PrintWoker(mWorkers);
}

int main()
{
    test();
    return 0;
}