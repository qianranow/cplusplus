//
// Created by qianranow on 2022/1/26.
//

#include <iostream>

using namespace std;

int main()
{
    // 这种方式不能进行隐式转换，必须显示地转换
    char *p = (char *)malloc(64);
    return 0;
}