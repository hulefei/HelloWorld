//
//  mainVirtualDemo.cpp
//  HelloCpp
//
//  Created by Hanson on 13-10-12.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include "Circle.h"
#include "SubCircle.h"

int main() {
   Circle* circle = new Circle();
    circle->draw1();
//    circle->draw2();
    
    Circle* circle2 = new Circle(100);
    circle2->draw1();

    
//    SubCircle* subCircle = new SubCircle();
    
}
