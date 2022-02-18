//
// Created by qianranow on 2022/2/8.
//

#include <iostream>
using namespace std;
#include <string>
//友元是赋予全局函数，类的成员函数，类有访问别的类的私有成员权限
//注意：友元函数不是类的成员函数

class Building
{
    //声明这个全局函数为Building类的友元函数
    friend void GoodGay(Building &bd);
public:
    Building()
    {
        keting = "客厅";
        woshi = "卧室";
    }

private:
    int add()
    {
        return 100;
    }
public:
    string keting;
private:
    string woshi;
};

void GoodGay(Building &bd)
{
    cout << "好基友访问：" << bd.keting << endl;
    cout << "好基友访问：" << bd.woshi << endl;
    int a = bd.add();
    cout << "好基友访问：" << a << endl;
}

void test01()
{
    Building my;
    GoodGay(my);
}

int main()
{
    test01();
    return 0;
}