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

double Box::volume() {
    return length * width * height;
}


