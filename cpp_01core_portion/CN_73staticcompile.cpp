//
// Created by qianranow on 2022/2/16.
//

#include <iostream>
using namespace std;

//动态联编（晚绑定）：在运行阶段才确定调用哪个函数
//作用：可以晚绑定函数调用地址，这样可以扩展功能，不修改前面的代码的基础上进行项目的扩充
class Animal
{
public:
    //虚函数：告诉编译器这个函数要晚绑定
    virtual void speak()
    {
        cout << "Animal speak" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Dog speak" << endl;
    }
};

class Dog1 : public Animal
{
public:
    void speak()
    {
        cout << "Dog1 speak" << endl;
    }
};

void test01()
{
    Animal an;
    an.speak();//静态联编（早绑定）：在编译阶段就确定了调用speak这个函数
}

//业务层
//类型转换问题
//子类转换成父类（向上转换）：编译器认为指针的寻址范围缩小了，所以是安全的
//父类转换成子类（向下转换）：编译器认为指针的寻址范围扩大了，不安全
void doLogin(Animal *animal)
{
    animal->speak();
}

void test02()
{
    Dog *dog = new Dog;
    doLogin(dog);

    Dog1 *dog1 = new Dog1;
    doLogin(dog1);
}

int main()
{
    test02();
    return 0;
}
