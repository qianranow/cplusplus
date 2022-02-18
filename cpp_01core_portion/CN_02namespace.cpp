//
// Created by qianranow on 2022/1/24.
//

#include <iostream>
#include "CN_02test.h"
using namespace std;

// 命名空间
namespace A { // A是空间的名字
    int a;
    namespace B {
        int b = 40;
    }
    void func() {

    }
}
namespace A { // A是空间的名字
    int c = 30;
}

int mya = 10;

// 类似于 static int d = 50;
namespace {
    int d = 50;
}

void test01() {
    namespace makeA = A;
    cout << makeA::c << endl;
}

int main()
{
    // 就近原则
    int mya = 20;
    cout << "mya=" << mya << endl;
    cout << "::mya=" << ::mya << endl;
    cout << A::c << endl;
    cout << A::B::b << endl;
    myMaker1::func();
    cout << d << endl;
    test01();
    return 0;
}