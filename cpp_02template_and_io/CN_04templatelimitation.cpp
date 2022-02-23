//
// Created by qianranow on 2022/2/18.
//

#include <iostream>
#include <string>
using namespace std;

template<class T>
void func(T a, T b)
{
    if (a > b)
    {
        cout << "a>b" << endl;
    }
    else
    {
        cout << "a<=b" << endl;
    }
}

void test()
{
    //如果传入的是数组名，那么函数模板中比较函数名的大小就没有意义
    int arr[20];
    int arr2[30];
    func(arr, arr2);
}

class Maker
{
public:
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

public:
    string name;
    int age;
};

template<class T>
void myFunc(T &a, T &b)
{
    if (a > b)
    {
        cout << "a>b" << endl;
    }
    else
    {
        cout << "a<=b" << endl;
    }
}
//不建议具体化函数模板，因为没有通用性
//具体化函数模板，注意上面的函数模板要有，才能具体化
template<>void myFunc<Maker>(Maker &a, Maker &b)
{
    cout << "函数模板的具体化" << endl;
    if (a.age > b.age)
    {
        cout << "a>b" << endl;
    }
    else
    {
        cout << "a<=b" << endl;
    }
}

void test02()
{
    Maker m1("aaa", 10);
    Maker m2("bbb", 20);
    myFunc(m1, m2);
}

int main()
{
    test02();
    return 0;
}