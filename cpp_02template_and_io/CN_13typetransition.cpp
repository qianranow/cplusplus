//
// Created by qianranow on 2022/2/22.
//

#include <iostream>
using namespace std;

//静态转换
//1.基础类型转换
void test01()
{
    char a = 'a';
    //static_cast<要转到的类型>(将谁转换)
    double d = static_cast<double>(a);
    double d1 = (double)a;
}
//2.有层次关系类的指针或引用转换
class Father
{

};

class Son : public Father
{

};

class Other
{

};

void test02()
{
    Father *f = NULL;
    Son *s = NULL;
    //向下转，不安全
    Son *s1 = static_cast<Son*>(f);
    //向上转，安全
    Father *f1 = static_cast<Father*>(s);
    //没有继承关系的类之间的指针不能转换
    //Other *o = static_cast<Other*>(s); err
}

void test03()
{
    Father f;
    Son s;
    Father &ref_f = f;
    Son &ref_s = s;
    //向上，安全
    Father &f1 = static_cast<Father&>(ref_s);
    //向下，不安全
    Son & s1 = static_cast<Son&>(ref_f);
}

//动态转换
void test04()
{
    char a = 'a';
    //double d = dynamic_cast<double>(a);err，基础类型不能使用动态转换
    Father *f = NULL;
    Son *s = NULL;
    //向上，安全
    Father *f1 = dynamic_cast<Father*>(s);
    //向下，不安全，会检查
    //Son *s1 = dynamic_cast<Son*>(f);// error: 'Father' is not polymorphic
}
//发生多态时，向下转换，动态转换就可以
class Father2
{
public:
    virtual void func(){};
};

class Son2 : public Father2
{
public:
    virtual void func(){};
};

void test05()
{
    Father2 * f = new Son2;
    Son2 *s = dynamic_cast<Son2 *>(f);

    Father2 f2;
    Father2 &ref_f = f2;
    Son2 &s2 = dynamic_cast<Son2&>(f2);
}

//常量转换
void test06()
{
    const int *p = NULL;
    //const -> 不带const
    int *newP = const_cast<int*>(p);

    int *pp = NULL;
    const int *newPP = const_cast<const int*>(pp);

}

//重新解释转换
void test07()
{
    int a = 10;
    int *p = reinterpret_cast<int *>(a);
    cout << p << endl;

    Father *f = NULL;
    Other *o = reinterpret_cast<Other*>(f);
}

int main()
{
    test07();
    return 0;
}