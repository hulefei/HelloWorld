//
//  IntroLayer.m
//  NCLabelTTF
//
//  Created by Hanson on 13-2-18.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//


// Import the interfaces
#import "IntroLayer.h"

#pragma mark - IntroLayer
@implementation IntroLayer

// Helper class method that creates a Scene with the HelloWorldLayer as the only child.
- (id)init {
    if (self = [super init]) {
        CGSize winSize = [[CCDirector sharedDirector] winSize];
        CGPoint winCenter = ccp(winSize.width * 0.5,winSize.height * 0.5);
        
        CCLabelTTF *label = [[CCLabelTTF alloc] initWithString:@"Hello" fontName:@"Arial" fontSize:64];
        label.position = winCenter;
        [self addChild:label];
    }
    return self;
}
@end
