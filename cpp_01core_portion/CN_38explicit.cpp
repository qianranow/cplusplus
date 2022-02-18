//
// Created by qianranow on 2022/2/7.
//

#include <iostream>
using namespace std;

class Maker
{
public:
    //explicit只能放在构造函数前面，构造函数只有一个参数或者其他参数有默认值时
    explicit Maker(int n) //防止编译器优化Maker m=10;这种格式
    {

    }
};

int main()
{
    //Maker m = 10; //err
    return 0;
}