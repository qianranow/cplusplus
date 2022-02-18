//
// Created by qianranow on 2022/1/26.
//

#include <iostream>

using namespace std;
#define MA 128
const short ma = 128;
void func(short a)
{
    cout << "func(short a)" << endl;
}

void func(int a)
{
    cout << "func(int a)" << endl;
}
#define b 10
void test()
{
    const int a = 10;
    cout << b << endl;
}

int main()
{
//    func(ma);
    test();
    cout << b << endl;
    return 0;
}