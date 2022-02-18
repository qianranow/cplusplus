//
// Created by qianranow on 2022/1/27.
//

#include <iostream>
using namespace std;

// 值传递
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// 指针传递
void swap1(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// 引用传递
void swap2(int &a, int &b) // int &a=a, int &b=b
{
    int tmp = a;
    a = b;
    b = tmp;
}
void myprint(int &a, int &b)
{
    cout << "a=" << a << "b=" << b << endl;
}

int main()
{
    int a = 10;
    int b = 20;
    swap(a, b);
    myprint(a, b); //10, 20

    swap1(&a, &b);
    myprint(a, b);

    a = 10;
    b = 20;

    swap2(a, b);
    myprint(a, b);
    return 0;
}