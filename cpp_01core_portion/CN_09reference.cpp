//
// Created by qianranow on 2022/1/26.
//

#include <iostream>

using namespace std;

//Type& ref = val; // Type* const ref = &val;
void test01()
{
    int a = 10;
    int &b = a;
    b = 100;
    cout << a << endl;
}

void func(int &a) // int &a = a;
{
    a = 200;
}

void test02()
{
    int a = 10;
    func(a);
    cout << "a=" << a << endl;
}

int main()
{
    test02();
    return 0;
}