//
// Created by qianranow on 2022/2/23.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Maker
{
public:
    Maker(){}
//    Maker(const char*name, int age)
//    {
//        this->age = age;
//        strcpy(this->name, name);
//    }
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
public:
    //char name[64];
    string name;
    //string类中有一个成员指针char*，该指针指向存储字符串的空间
    //当我们把string类的数据存储到文件中，再读出来时，不能保证指针有效
    //string开辟的空间如果大于16个字节就在堆区，小于就在栈区
    //注意：当文件读写时，类中的成员变量不要有string类型
    int age;
};

//写文件
void test01()
{
//    Maker m1("string类中有一个成员指针char*，该指针指向存储字符串的空间string类中有一个成员指针char*，该指针指向存储字符串的空间string类中有一个成员指针char*，该指针指向存储字符串的空间string类中有一个成员指针char*，该指针指向存储字符串的空间string类中有一个成员指针char*，该指针指向存储字符串的空间", 20);
//    Maker m2("贝吉塔", 22);

    Maker m1("悟空", 20);
    Maker m2("贝吉塔", 22);

    ofstream  ofs;
    ofs.open("../test.txt", ios::out|ios::trunc|ios::binary);
    if (!ofs.is_open())
    {
        cout << "打开失败" << endl;
    }
    //写
    ofs.write((const char *)&m1, sizeof(Maker));
    ofs.write((const char *)&m2, sizeof(Maker));

    ofs.close();
}

void test02()
{
    ifstream  ifs;
    ifs.open("../test.txt", ios::in|ios::binary);
    if (!ifs.is_open())
    {
        cout << "打开失败" << endl;
    }

    //读
    Maker m1;
    Maker m2;
    ifs.read((char *)&m1, sizeof(Maker));
    ifs.read((char *)&m2, sizeof(Maker));

    cout << "Name:" << m1.name << "Age:" << m1.age << endl;
    cout << "Name:" << m2.name << "Age:" << m2.age << endl;

    ifs.close();
}

int main()
{
    test01();
    test02();
    return 0;
}