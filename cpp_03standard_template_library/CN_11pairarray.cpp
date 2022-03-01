//
// Created by qianranow on 2022/2/25.
//

#include <iostream>
#include <string>
using namespace std;

//pair对组
//pair对组是一个类，类中有两个公有的成员变量
//对组通常用来接受key-value这样的元素

int main()
{
    pair<string, int> myp("aaa", 10);
    cout << myp.first << " " << myp.second << endl;
    pair<int, string> myp1(1, "悟空");
    cout << myp1.first << " " << myp1.second << endl;

    //key->value

    return 0;
}