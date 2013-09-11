//
//  Carton.cpp
//  HelloCpp
//
//  Created by Hanson on 13-9-12.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include "Carton.h"
#include <iostream>
#include <cstring>

Carton::Carton(const char *pStr) {
    std::cout << "Carton constructor" << std::endl;
    pMaterial = new char[strlen(pStr) + 1];
    std::strcpy(pMaterial, pStr);
}

Carton::~Carton() {
    std::cout << "~Carton destructor" << std::endl;
    delete [] pMaterial;
}