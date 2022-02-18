//
// Created by qianranow on 2022/2/11.
//

#include <iostream>
#include "../includes/CN_52myarray.h"
using namespace std;

void test()
{
    MyArray arr;
    for (int i = 0; i < 20; ++i)
    {
        arr[i] = i + 10;
    }
    for (int i = 0; i < 20; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void test02()
{
    MyArray arr;
    for (int i = 0; i < 20; ++i)
    {
        arr[i] = i + 10;
    }
    for (int i = 0; i < 20; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    MyArray arr2;
    arr2 = arr;
    for (int i = 0; i < 20; ++i)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << arr2.Size() << endl;
}

int main()
{
    test02();
    return 0;
}