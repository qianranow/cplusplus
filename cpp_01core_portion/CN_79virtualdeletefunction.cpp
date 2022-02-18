//
// Created by qianranow on 2022/2/17.
//

#include <iostream>
using namespace std;
//虚析构函数是为了解决基类指针指向派生类对象，并用基类指针释放派生类对象
class Animal
{
public:
    Animal()
    {
        cout << "Animal的构造" << endl;
    }
    //虚构函数会调用子类的析构函数
//    virtual ~Animal()
//    {
//        cout << "Animal的析构" << endl;
//    }
    //纯虚析构函数，有纯虚析构函数的类是抽象类，不能实例化对象
    //注意：纯虚析构函数需要在类外实现
    virtual ~Animal() = 0;
};

//在类外实现纯虚析构函数
Animal::~Animal()
{
    cout << "Animal的析构" << endl;
}

class Son : public Animal
{
public:
    Son()
    {
        cout << "Son的构造" << endl;
        pName = new char[64];
        memset(pName, 0, 64);
        strcpy(pName, "小花");
    }
    ~Son()
    {
        cout << "Son的析构" << endl;
        if (pName != NULL)
        {
            delete[] pName;
            pName = NULL;
        }
    }

public:
    char *pName;
};

void test()
{
    Animal *animal = new Son;
    delete animal;//静态联编
}

int main()
{
    //1.重载，同一作用域的同名函数
    //2.重写(覆盖)：(1)有继承；(2)子类重写父类的virtual函数；(3)函数的返回值，函数名字，函数参数，必须和基类中的虚函数一致
    //3.重定义(隐藏)：(1)有继承；(2)子类重新定义父类的同名成员（非virtual函数）
    test();
    return 0;
}