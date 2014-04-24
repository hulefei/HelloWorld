//
//  mainPointDemo.cpp
//  HelloCpp
//
//  Created by Hanson on 13-12-15.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include <stdio.h>
#include <iostream>
//#include <cstdlib>

using namespace std;

class A {
public:
    int value;
    
    A(){value = 100;}
    int getValue() const { return value; }
    
};

//int main() {
//    
//    A *a = new A();
////    A a;
//    cout << (*a).getValue() << endl;
//    
//    return 0;
////    return EXIT_FAILURE;
//}

//const string& manip() {
//    return "hello";
//}

