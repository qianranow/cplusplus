//
// Created by qianranow on 2022/2/17.
//

#include <iostream>
using namespace std;

//每个类有虚函数表指针
//虚函数表指针对应自己的虚函数表
//父类会拷贝一份虚函数表指针和虚函数表给子类
//编译器为了初始化从父类继承过来的虚函数表指针，编译器在我们的
//所有构造函数中添加了初始化虚函数表指针的代码，让从父类继承过来的
//虚函数表指针指向子类自己的虚函数表
class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal speak()" << endl;
    }
    virtual void speak1()
    {
        cout << "Animal speak1()" << endl;
    }
};

void test()
{
    cout << sizeof(Animal) << endl;
}

int main()
{
    test();
    return 0;
}