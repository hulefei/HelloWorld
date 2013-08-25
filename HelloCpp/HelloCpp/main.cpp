//
//  main.cpp
//  HelloCpp
//
//  Created by Hanson on 13-4-24.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

void test1();
void test2();

int main(int argc, const char * argv[]) {
//    test1();
    test2();
    return 0;
}

void test1() {
    double d = 1.332;
    int i = static_cast<int>(d);
    cout << i;
}
void test2() {
    cout << "int size :" << sizeof(int) << endl;
    cout << "double size :" << sizeof(double) << endl;
    cout << "float size :" << sizeof(float) << endl;
    cout << "long size :" << sizeof(long) << endl;
}
void 

