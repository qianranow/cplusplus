//
// Created by qianranow on 2022/2/11.
//

#include <iostream>
using namespace std;

//公有继承
class Father
{
public:
    int a;
private:
    int b;
protected:
    int c;
};

class Son1 :public Father
{
public:
    void func()
    {
        a;
        c;
    }
    /*
     公有继承；
     1.父类的公有属性成员，到子类还是公有
     2.父类的私有属性成员，到子类不能访问
     3.父类的保护属性成员，到子类还是保护
     */
};

class Son2 :protected Father
{
public:
    void func()
    {
        a;
        c;
    }
    /*
     保护继承；
     1.父类的公有属性成员，到子类是保护
     2.父类的私有属性成员，到子类不能访问
     3.父类的保护属性成员，到子类还是保护
     */
};

class Son3 :private Father
{
public:
    void func()
    {
        a;
        c;
    }
    /*
     私有继承；
     1.父类的公有属性成员，到子类是私有
     2.父类的私有属性成员，到子类不能访问
     3.父类的保护属性成员，到子类是私有
     */
};

void test01()
{
    Son1 s1;
    s1.a;
}

void test02()
{
    Son2 s2;
}

void test03()
{
    Son3 s3;
}


int main()
{
    return 0;
}