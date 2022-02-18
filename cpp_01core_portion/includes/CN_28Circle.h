//
// Created by qianranow on 2022/1/28.
//

#ifndef CPLUSPL_CN_28CIRCLE_H
#define CPLUSPL_CN_28CIRCLE_H
#include <cmath>
#include <iostream>
#include "CN_28Point.h"
using namespace std;

class Circle
{
public:
    void SetR(int r);
    void SetHear(Point &p);
    void SetHear(int x, int y);
    int getR();
    Point getHear();
    void isPointAndCircle(Point &p);

private:
    int mR;
    Point mHear;
};

#endif //CPLUSPL_CN_28CIRCLE_H
