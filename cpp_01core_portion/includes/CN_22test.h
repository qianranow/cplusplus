//
// Created by qianranow on 2022/1/28.
//

#ifndef CPLUSPL_CN_22TEST_H
#define CPLUSPL_CN_22TEST_H
#include <stdio.h>

//这是告诉c++编译器，找下面的函数，要以C语言的方式去寻找
#ifdef __cplusplus
extern "C"
{
#endif
    void func();
#ifdef __cplusplus
}
#endif

#endif //CPLUSPL_CN_22TEST_H
