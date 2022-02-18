//
// Created by qianranow on 2022/2/7.
//

#include <iostream>
using namespace std;

class Maker
{
public:
//    Maker() {
//        cout << "无参构造函数" << endl;
//    }

//    Maker(int a) {
//        cout << "有参构造函数" << endl;
//    }

    Maker(const Maker &m)
    {
        cout << "拷贝构造函数" << endl;
    }

//    ~Maker()
//    {
//        cout << "析构函数" << endl;
//    }
};

//1.如果程序员提供了有参构造，那么编译器不会提供默认的构造函数，但是会提供默认的拷贝构造
void test01()
{
    // Maker m; //err
//    Maker m(10); //调用有参构造
//    Maker m2(m); //调用默认的拷贝构造
}

//2.如果程序员提供了拷贝构造函数，那么编译器不会提供默认的构造函数和拷贝构造函数
void test02()
{
    //Maker m;
}

int main()
{
    test01();
    return 0;
}