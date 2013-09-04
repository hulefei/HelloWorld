//
//  main.cpp
//  HelloCpp
//
//  Created by Hanson on 13-4-24.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include "Box.h"

void test1();
void test2();
double boxSurface(const Box &theBox);

int main(int argc, const char * argv[]) {
//    test1();
//    test2();
    
//    Box firstBox = {80.0,50.0,40.0};
//    std::cout << firstBox.width << "by"
//        << firstBox.width << "by"
//        << firstBox.height << std::endl;
//    
//    std::cout << "Volume of first Box object is " << firstBox.volume();
    
    Box *firstBox = new Box(80.0,50.0,40.0);
    std::cout << boxSurface(*firstBox) << std::endl;
    std::cout << "Volume of first Box object is " << firstBox->volume();
    
    delete firstBox;
    
    return 0;
}

//friend
double boxSurface(const Box &theBox) {
    return theBox.length;
}

void test1() {
    double d = 1.332;
    int i = static_cast<int>(d);
    std::cout << i;
}
void test2() {
    std::cout << "int size :" << sizeof(int) << std::endl;
    std::cout << "double size :" << sizeof(double) << std::endl;
    std::cout << "float size :" << sizeof(float) << std::endl;
    std::cout << "long size :" << sizeof(long) << std::endl;
}

