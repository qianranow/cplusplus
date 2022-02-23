//
// Created by qianranow on 2022/2/21.
//

#ifndef CPLUSPL_CN_10MAKER_HPP
#define CPLUSPL_CN_10MAKER_HPP

#include <iostream>
using namespace std;
template<class NameTyep, class AgeType>
class Maker
{
public:
    Maker(NameTyep name, AgeType age);
    void printMaker();
public:
    NameTyep name;
    AgeType age;
};

template<class NameType, class AgeType>
Maker<NameType, AgeType>::Maker(NameType name, AgeType age)
{
    cout << "构造函数" << endl;
    this->name = name;
    this->age = age;
}

template<class NameType, class AgeType>
void Maker<NameType, AgeType>::printMaker()
{
    cout << "Name:" << this->name << "Age:" << this->age << endl;
}

#endif //CPLUSPL_CN_10MAKER_HPP
