//
// Created by qianranow on 2022/2/11.
//

#include "CN_64mystring.h"

MyString::MyString()
{
    this->pM = new char [1];
    this->pM[0] = '\0';
    this->mSize = 0;
}
MyString::~MyString()
{
    if (this->pM != NULL)
    {
        delete[] this->pM;
        this->pM = NULL;
    }
}
MyString::MyString(int n, char c)
{
    this->pM = new char[n+1];
    for (int i = 0; i < n; ++i)
    {
        this->pM[i] = c;
    }
    this->pM[n] = '\0';
    this->mSize = n;
}
MyString::MyString(const MyString &str)
{
    this->pM = new char[strlen(str.pM)+1];
    strcpy(this->pM, str.pM);
    this->mSize = str.mSize;
}
MyString&MyString::operator=(const MyString &str)
{
    //1.释放原来空间
    if (this->pM != NULL)
    {
        delete[] this->pM;
        this->pM = NULL;
    }
    //2.申请空间
    this->pM = new char[strlen(str.pM)+1];
    //3.拷贝数据
    strcpy(this->pM, str.pM);
    this->mSize = str.mSize;
    return *this;
}

MyString MyString::operator+(const MyString &str)
{
    //获取s3要开辟的空间大小
    int newlen = this->mSize + str.mSize + 1;
    //1.定义一个临时变量
    MyString tmp;
    //2.释放原来的空间
    if (tmp.pM != NULL)
    {
        delete[] tmp.pM;
        tmp.pM = NULL;
    }
    //3.申请新的空间
    tmp.pM = new char[newlen];
    memset(tmp.pM, 0, newlen);
    tmp.mSize = this->mSize + str.mSize;

    //4.追加字符到空间中
    strcat(tmp.pM, this->pM);
    strcat(tmp.pM, str.pM);

    return tmp;
}
MyString MyString::operator+(const char *s)
{
    int newlen = this->mSize + strlen(s);
    char *newspace = new char[newlen+1];
    memset(newspace, 0, newlen+1);
    strcat(newspace, this->pM);
    strcat(newspace, s);
    MyString tmp;
    if (tmp.pM != NULL)
    {
        delete[] tmp.pM;
        tmp.pM = NULL;
    }
    tmp.pM = newspace;
    tmp.mSize = newlen;
    return tmp;
}
MyString &MyString::operator+=(const MyString &str)
{
    int newlen = this->mSize + str.mSize;
    char *newspace = new char[newlen+1];
    memset(newspace, 0, newlen+1);
    strcat(newspace, this->pM);
    strcat(newspace, str.pM);
    if (this->pM != NULL)
    {
        delete[] this->pM;
        this->pM = NULL;
    }
    this->pM = newspace;
    this->mSize = newlen;
    return *this;
}
MyString &MyString::operator+=(const char *s)
{
    int newlen = this->mSize + strlen(s);
    char *newspace = new char[newlen+1];
    memset(newspace, 0, newlen+1);
    strcat(newspace, this->pM);
    strcat(newspace, s);
    if (this->pM != NULL)
    {
        delete[] this->pM;
        this->pM = NULL;
    }
    this->pM = newspace;
    this->mSize = newlen;
    return *this;
}
int MyString::Size()
{
    return this->mSize;
}
char &MyString::operator[](int index)
{
    return this->pM[index];
}

ostream &operator<<(ostream &out, MyString &str)
{
    out << str.pM;
    return out;
}

istream &operator>>(istream &in, MyString &str)
{
    //cin>>s4;
    //用书输入的字符串要存储到s4.pM指向的堆区空间
    //1.定义临时空间
    char tmp[1024] = {0};
    //2.获取用户输入的信息
    in >> tmp;
    //3.释放s4的空间
    if (str.pM != NULL)
    {
        delete[] str.pM;
        str.pM = NULL;
    }
    //4.申请新的空间
    str.pM = new char[strlen(tmp)+1];
    memset(str.pM, 0, strlen(tmp)+1);
    //5.拷贝用户输入的信息到堆区空间
    strcpy(str.pM, tmp);
    str.mSize = strlen(tmp);
    return in;
}