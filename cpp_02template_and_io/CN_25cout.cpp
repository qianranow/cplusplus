//
// Created by qianranow on 2022/2/23.
//

#include <iostream>
#include <iomanip>
using namespace std;

void test01()
{
    cout.put('c');
    cout.put('a').put('b').put('c');
}

void test02()
{
    char buf[] = "hello world";
    cout.write(buf, strlen(buf));
}

//通过流成员函数实现格式化的输出
void test03()
{
    int num = 99;
    cout.width(20);//设置宽度
    cout.fill('*');//填充
    cout.setf(ios::left);//让数据在左边
    cout.unsetf(ios::dec);//卸载十进制
    cout.setf(ios::hex);//安装十六进制
    cout.setf(ios::showbase);//显示基数
    cout.unsetf(ios::hex);
    cout.setf(ios::oct);

    cout << num << endl;
}

//通过控制符来格式化输出，引入头文件iomanip
void test04()
{
    int num = 99;
    cout << setw(20); //设置宽度
    cout << setfill('~');
    cout << setiosflags(ios::showbase);
    cout << setiosflags(ios::left);
    cout << hex;
    cout << oct;
    cout << dec;
    cout << num << endl;
}

void test05()
{
    double d = 20.22;
    cout << setiosflags(ios::fixed);//设置显示浮点数
    cout << setprecision(10);//显示小数点后10位
    cout << d << endl;
}

int main()
{
    test05();
    return 0;
}