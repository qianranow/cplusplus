//
// Created by qianranow on 2022/2/17.
//

#include <iostream>
using namespace std;

//1.依赖倒转：业务层依赖抽象层，实现层也依赖抽象层
//抽象层
//有纯虚函数的类叫抽象类，不能实例化对象
//如果子类继承抽象类，子类必须实现抽象类的所有纯虚函数，不然子类也变为抽象类
class rule
{
public:
    //纯虚函数
    virtual int getnum(int a, int b) = 0;
};

//实现层
class plus_rule : public rule
{
public:
    virtual int getnum(int a, int b)//重写父类的虚函数，依赖抽象层
    {
        return a + b;
    }
};

//2.开闭原则：对修改源代码关闭，对扩展新功能开放
class minus_rule : public rule
{
public:
    virtual int getnum(int a, int b)
    {
        return a - b;
    }
};

//业务层
int doLogin(rule *cal)
{
    int a = 10;
    int b = 20;
    int ret = cal->getnum(a, b);//依赖抽象层
    return ret;
}

void test()
{
    rule *r = NULL;
    r = new plus_rule;
    cout << doLogin(r) << endl;
    delete r;

    r = new minus_rule;
    cout << doLogin(r) << endl;
    delete r;
}

void test02()
{
    //抽象类不能实例化对象
    //rule r;
}

class Maker
{
public:
    virtual void func1() = 0;
    virtual void func2() = 0;
};

class Son : public Maker
{
public:
    virtual void func1()
    {

    }
    virtual void func2()
    {

    }
};

void test03()
{
    Son s;
}

int main()
{
    test();
    return 0;
}