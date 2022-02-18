//
// Created by qianranow on 2022/1/28.
//

#include <iostream>
using namespace std;

class Maker
{
public:
    int a; //成员变量
    void func() //成员方法
    {
        cout << "func" << endl;
    }
};

int main()
{
    Maker m;
    return 0;
}