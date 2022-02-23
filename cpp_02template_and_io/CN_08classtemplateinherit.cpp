//
// Created by qianranow on 2022/2/19.
//

#include <iostream>
#include <string>
using namespace std;

template<class T>
class Father
{
public:
    Father()
    {
        m = 20;
    }
public:
    T m;
};

//普通类 继承 类模板
class Son : public Father<int>//要告诉编译器父类的泛型数据类型具体是什么类型
{

};

//类模板 继承 类模板
template<class T1, class T2>
class Son2 : public Father<T2>//要告诉编译器父类的泛型数据类型具体是什么类型
{

};

void test()
{
    Son2<int, int> s;
    cout << s.m << endl;
}

int main()
{
    test();
    return 0;
}