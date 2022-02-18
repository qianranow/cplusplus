//
// Created by qianranow on 2022/1/27.
//

#include <iostream>

using namespace std;

void test01()
{
    char* p = "翠花";
    char* &p1 = p;
    cout << p1 << endl;
}

void func(char* &tmp) // char* &tmp = mp;
{
    char* p = (char*)malloc(64);
    memset(p, 0, 64);
    strcpy(p, "小花");
    tmp = p;
}

void test02()
{
    char* mp = NULL;
    func(mp);
    cout << mp << endl;
}

int main()
{
    test02();
    return 0;
}