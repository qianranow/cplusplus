//
// Created by qianranow on 2022/2/11.
//

#include <iostream>
using namespace std;

//爷爷
//被虚继承的基类叫虚基类
class Animal
{
public:
    Animal()
    {
        mA = 500;
    }
public:
    int mA;
};
//用虚继承的方法解决菱形继承中的二义性问题
//虚继承
class Sheep : virtual public Animal
{

};
//虚继承
class Camel: virtual public Animal
{

};

class SheepCamel : public Sheep, public Camel
{

};

void test()
{
    SheepCamel sc;
    cout << sc.mA << endl;
    //虚继承的原理
    //1.编译器给类添加了一个指针，指针指向类似于表的组织，该表记录了该指针距离变量的偏移量
    //2.当子类多继承两个父类，那么只有一份成员变量，然后有两个指针
}

void test02()
{
    Sheep s;
    cout << s.mA << endl;
    // 根据虚表指针查找
    cout << ((Animal *)(int *)&s+2)->mA << endl;
}

int main()
{
    test02();
    return 0;
}