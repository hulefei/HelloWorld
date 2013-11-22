//
//  Circle.cpp
//  HelloCpp
//
//  Created by Hanson on 13-10-12.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include "Circle.h"
using namespace std;


void Circle::draw1() {
    cout << "draw1:" << totalI << endl;
}

void Circle::draw2() {
    cout << "draw2" << endl;
}


Circle::Circle() {
    totalI = 0;
    cout << "Circle constructor" << endl;
}

Circle::Circle(int i) {
    totalI = i;
    cout << "Circle(int i) constructor" << endl;
}