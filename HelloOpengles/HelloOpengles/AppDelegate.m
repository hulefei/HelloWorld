//
//  AppDelegate.m
//  HelloOpengles
//
//  Created by Hanson on 13-12-5.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    
    
    EAGLContext * context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2]; // 1
    GLKView *view = [[GLKView alloc] initWithFrame:[[UIScreen mainScreen] bounds]]; // 2
    view.context = context; // 3
    view.delegate = self; // 4
    [self.window addSubview:view]; // 5
    
    // Override point for customization after application launch.
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    return YES;
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect {
        
    glClearColor(0, 104.0/255.0, 55.0/255.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glEnable(GL_DEPTH_TEST);
    glLineWidth(3.0f);
    glEnable(GL_COLOR_MATERIAL);
    
    float axes_length = 0.2;
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor4f(1.0, 0, 0, 1);
    float linevertexs_x[6] = {0,0,0,axes_length,0,0};
    glVertexPointer(3,GL_FLOAT,0, linevertexs_x);
    glDrawArrays(GL_LINES,0, 2);
    
    glColor4f(0, 1.0, 0, 1);
    float linevertexs_y[6] = {0,0,0,0,axes_length,0};
    glVertexPointer(3,GL_FLOAT,0, linevertexs_y);
    glDrawArrays(GL_LINES,0, 2);
    
    
    glColor4f(0, 0, 1.0, 1);
    float linevertexs_z[6] = {0,0,0,0,0,axes_length};
    glVertexPointer(3,GL_FLOAT,0, linevertexs_z);
    glDrawArrays(GL_LINES,0, 2);
    
    //glColor4f(1, 1, 1, 1);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_COLOR_MATERIAL);
}



@end
