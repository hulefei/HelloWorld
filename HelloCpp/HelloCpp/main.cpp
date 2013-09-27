//
//  main.cpp
//  HelloCpp
//
//  Created by Hanson on 13-4-24.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include "Chapter7.h"

void chapter7();


//int main(int argc, const char * argv[]) {
//    chapter7();
//    return 0;
//}

void chapter7() {
    Chapter7 *chapter7 = new Chapter7();
//    chapter7->helloworld();
//    chapter7->method01();
//    chapter7->method02();
//    chapter7->method03();
//    chapter7->method04();
    chapter7->method05();
    
    delete chapter7;
}


