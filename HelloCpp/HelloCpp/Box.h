//
//  Box.h
//  HelloCpp
//
//  Created by Hanson on 13-9-3.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#ifndef HelloCpp_Box_h
#define HelloCpp_Box_h

class Box {
public:
    Box(double lengthValue=1.0, double widthValue=1.0, double heightValue=1.0);
    ~Box();
    
    double volume() const;
    int compareVolume(const Box &otherBox);
    
    friend double boxSurface(const Box &theBox);
    
private:
    double length;
    double width;
    double height;
};



#endif
