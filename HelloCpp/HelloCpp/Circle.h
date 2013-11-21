//
//  Circle.h
//  HelloCpp
//
//  Created by Hanson on 13-10-12.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#ifndef __HelloCpp__Circle__
#define __HelloCpp__Circle__

#include <iostream>
#include "Shape.h"

class Circle : public Shape {
public:
    void draw1();
    void draw2();
    
    Circle();
    Circle(int i);
    
    int totalI;
    
};
#endif /* defined(__HelloCpp__Circle__) */
