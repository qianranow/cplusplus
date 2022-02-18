//
// Created by qianranow on 2022/2/17.
//

#include <iostream>
using namespace std;

//多态
//同一个操作作用于不同的对象，可以有不同的解释，会产生不同的效果
//作用
//1.可以解决项目中的紧耦合问题，提供程序的可扩展性
//2.应用程序不必为每一个子类的功能调用编写代码，只需要对抽象的父类进行处理
//多态发生三条件
//1.有继承
//2.重写父类的虚函数
//3.父类指针指向子类对象
class People
{
public:
    //虚函数
    virtual void Mypro()
    {

    }
};

class xishi : public People
{
public:
    //重写父类的虚函数
    virtual void Mypro()
    {
        cout << "约西施" << endl;
    }
};

class wangzhaojun : public People
{
public:
    //重写父类的虚函数
    virtual void Mypro()
    {
        cout << "约王昭君" << endl;
    }
};

class diaochan : public People
{
public:
    //重写父类的虚函数
    virtual void Mypro()
    {
        cout << "约貂蝉" << endl;
    }
};

//同一个操作
void doLogin(People *pro)
{
    pro->Mypro();//产生不同的效果
}

void test()
{
    People *pro = NULL;
    pro = new xishi;
    doLogin(pro);
    delete pro;

    pro = new wangzhaojun;
    doLogin(pro);
    delete pro;


    pro = new diaochan;
    doLogin(pro);
    delete pro;
}

int main()
{
    test();
    return 0;
}
