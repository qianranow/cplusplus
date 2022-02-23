//
// Created by qianranow on 2022/2/22.
//

#include <iostream>
using namespace std;

int printArray(int arr[], int len)
{
    if (arr == NULL)
    {
        return -1;
    }
    if (len == 0)
    {
        return 0;
    }
}
//C语言处理异常的方法的缺陷：
//1.返回值意思不明确
//2.返回值只能返回一条信息
//3.返回值可以忽略
//C++的异常可以解决上面的问题
void test()
{
    int *arr = NULL;
    int len = 0;
    printArray(arr, len);
}

int main()
{
    return 0;
}