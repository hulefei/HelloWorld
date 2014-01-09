//
//  mainPointDemo.cpp
//  HelloCpp
//
//  Created by Hanson on 13-12-15.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;


int main1() {

    int i = 42;
    int& r1 = i;
//    const int& r2 = i;
    
    
    cout << i << ":" << r1 << ":"  << endl;
    
    return 0;
}