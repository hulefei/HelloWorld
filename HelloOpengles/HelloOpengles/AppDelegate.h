//
//  AppDelegate.h
//  HelloOpengles
//
//  Created by Hanson on 13-12-5.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

typedef struct {
    GLfloat x;
    GLfloat y;
    GLfloat z;
} Vertex3D;

typedef struct {
    Vertex3D v1;
    Vertex3D v2;
    Vertex3D v3;
} Triangle3D;

static inline Vertex3D Vertex3DMake(CGFloat inX, CGFloat inY, CGFloat inZ) {
    Vertex3D ret;
    ret.x = inX;
    ret.y = inY;
    ret.z = inZ;
    return ret;
}

static inline Triangle3D Triangle3DMake(Vertex3D vertex1, Vertex3D vertex2, Vertex3D vertex3) {
    Triangle3D ret;
    ret.v1 = vertex1;
    ret.v2 = vertex2;
    ret.v3 = vertex3;
    return ret;
}

@interface AppDelegate : UIResponder <UIApplicationDelegate, GLKViewDelegate> {
    GLuint _vertexBuffer;
    GLuint _indexBuffer;
}

@property (strong, nonatomic) UIWindow *window;

@end
