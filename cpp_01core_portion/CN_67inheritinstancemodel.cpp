//
// Created by qianranow on 2022/2/11.
//

#include <iostream>
using namespace std;

//g++ -fdump-lang-class xxx.cpp 查看对象内存布局
class Father
{
public:
    int a;
private:
    int b;
protected:
    int c;
};

class Son : public Father
{
public:
    int s1;
    int s2;
};

int main()
{
    Son s1;
    return 0;
}