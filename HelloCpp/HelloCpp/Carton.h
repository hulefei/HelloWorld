//
//  Carton.h
//  HelloCpp
//
//  Created by Hanson on 13-9-12.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#ifndef HelloCpp_Carton_h
#define HelloCpp_Carton_h
#include "Box.h"

class Carton : public Box {
public:
    Carton(const char *pStr = "Cardboard");
    ~Carton();
    
private:
    char *pMaterial;
};

#endif
