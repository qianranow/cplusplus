//
// Created by qianranow on 2022/2/11.
//

#ifndef CPLUSPL_CN_64MYSTRING_H
#define CPLUSPL_CN_64MYSTRING_H
#include <iostream>
using namespace std;
class MyString
{
    friend ostream &operator<<(ostream &out, MyString &str);
    friend istream &operator>>(istream &in, MyString &str);
public:
    MyString();
    MyString(int n, char c);
    MyString(const MyString &str);
    MyString&operator=(const MyString &str);
    ~MyString();
    MyString operator+(const MyString &str);
    MyString operator+(const char *s);
    MyString &operator+=(const MyString &str);
    MyString &operator+=(const char *s);
    int Size();
    char &operator[](int index);

private:
    char *pM;//指向堆区空间
    int mSize;
};

#endif //CPLUSPL_CN_64MYSTRING_H
