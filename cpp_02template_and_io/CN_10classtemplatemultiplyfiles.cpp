//
// Created by qianranow on 2022/2/19.
//

#include <iostream>
#include <string>
#include "CN_10Maker.hpp"

using namespace std;

int main()
{
    //1.调用类模板时，要进行第二次编译，要把泛型的数据类型替换为具体的类型，
    //这时需要知道函数体，但是函数的实现在.cpp中，那么调用类模板的.cpp没有引入实现.cpp，
    //只引入.h，所以报错
    //2.解决方法：把成员函数放到.h中，然后把.h改为.hpp，然后在调用成员函数的地方，引入.hpp
    //3.为什么.hpp中有成员的实现，然后在调用类模板的地方引入.hpp，不会报重定义
    //4.类的成员函数默认申请为内联函数，在链接时，连接器会对重复的成员函数进行处理，只保留
    //一份成员函数，所以不会进行报错
    Maker<string, int> m("悟空", 20);
    m.printMaker();
    return 0;
}