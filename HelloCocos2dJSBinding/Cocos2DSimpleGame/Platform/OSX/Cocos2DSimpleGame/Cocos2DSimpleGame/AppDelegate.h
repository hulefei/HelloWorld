//
//  AppDelegate.h
//  Cocos2DSimpleGame
//
//  Created by Hanson on 13-3-6.
//  Copyright Hanson 2013年. All rights reserved.
//


#import "cocos2d.h"

@interface Cocos2DSimpleGameAppDelegate : NSObject <NSApplicationDelegate>
{
	NSWindow	*window_;
	CCGLView	*glView_;
}

@property (assign) IBOutlet NSWindow	*window;
@property (assign) IBOutlet CCGLView	*glView;

- (IBAction)toggleFullScreen:(id)sender;

@end
