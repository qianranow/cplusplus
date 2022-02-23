//
// Created by qianranow on 2022/2/21.
//

#include <iostream>
#include "string"
#include "CN_12MyArray.hpp"
using namespace std;

class Maker
{
public:
    Maker(){}
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
public:
    string name;
    int age;
};

void printMaker(MyArray<Maker> &arr)
{
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << "姓名:" << arr[i].name << "年龄:" << arr[i].age << endl;
    }
}

void test()
{
    MyArray<Maker> myArray(4);
    Maker m1("小花", 18);
    Maker m2("短笛", 30);
    Maker m3("小林", 19);
    myArray.Push_Back(m1);
    myArray.Push_Back(m2);
    myArray.Push_Back(m3);
    printMaker(myArray);

    MyArray<int > myInt(10);
    for (int i = 0; i < 10; ++i)
    {
        myInt.Push_Back(i+1);
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << myInt[i] << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}