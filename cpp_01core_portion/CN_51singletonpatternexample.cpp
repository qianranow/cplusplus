//
// Created by qianranow on 2022/2/8.
//

#include <iostream>
using namespace std;
#include <string>

//需求，获取打印机使用的次数
class Printer
{
private:
    Printer()
    {
       mcount = 0;
    }
    Printer(const Printer &printer)
    {

    }

public:
    static Printer *getPrinter()
    {
        return p;
    }
    void printPrinter(string name)
    {
        cout << name << ":打印" << endl;
        mcount++;
    }
    int getCount()
    {
        return mcount;
    }
private:
    int mcount;//记录打印机打印的次数
    static Printer *p;
};
Printer *Printer::p = new Printer;

void test()
{
    //销售部
    Printer *p1 = Printer::getPrinter();
    p1->printPrinter("销售部");

    //技术部
    Printer *p2 = Printer::getPrinter();
    p1->printPrinter("技术部");

    //公关部
    Printer *p3 = Printer::getPrinter();
    p1->printPrinter("公关部");

    Printer *p4 = Printer::getPrinter();
    cout << "打印机使用的次数:" << p4->getCount() << endl;
}

int main()
{
    test();
    return 0;
}