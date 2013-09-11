//
//  Box.cpp
//  HelloCpp
//
//  Created by Hanson on 13-9-3.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include <iostream>
#include "Box.h"

Box::Box(double lengthValue, double widthValue, double heightValue) {
    std::cout << "Box constructor called" << std::endl;
    length = lengthValue;
    width = widthValue;
    height = heightValue;
}

double Box::volume()const {
    return length * width * height;
}

int Box::compareVolume(const Box &otherBox) {
    double vol1 = this->volume();
    double vol2 = otherBox.volume();
    return vol1 > vol2 ? 1 : (vol1 < vol2 ? -1 : 0);
}

Box::~Box() {
    std::cout << "~Box destructor" << std::endl;
}
