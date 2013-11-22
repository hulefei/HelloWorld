#import "HelloWorldLayer.h"

@implementation HelloWorldLayer

+ (id)scene {
    
    CCScene *scene = [CCScene node];
    HelloWorldLayer *layer = [HelloWorldLayer node];
    [scene addChild:layer];
    return scene;
    
}

- (id)init {
    
    if ((self=[super init])) {
        CGSize winSize = [CCDirector sharedDirector].winSize;
        
        // 首先，我们往屏幕中间加入一个精灵
        _ball = [CCSprite spriteWithFile:@"ball.png" rect:CGRectMake(0, 0, 52, 52)];
        _ball.position = ccp(100, 100);
        [self addChild:_ball];
        
        //我们创建了world对象。当我们创建这个对象的时候，需要指定一个初始的重力向量。这里，我们设置y轴方向为-30，因此，所有的body都会往屏幕下面下落
        //我们还指定了一个值，用以指明对象不参与碰撞时，是否可以“休眠”。一个休眠的对象将不会花费处理时间，直到它与其实对象发生碰撞的时候才会“醒”过来
        b2Vec2 gravity = b2Vec2(0.0f, -30.0f);
        _world = new b2World(gravity);
        
        // Create ball body and shape
        b2BodyDef ballBodyDef;
        ballBodyDef.type = b2_dynamicBody;
        ballBodyDef.position.Set(100/PTM_RATIO, 300/PTM_RATIO);
        ballBodyDef.userData = _ball;
        _body = _world->CreateBody(&ballBodyDef);
        
        
        b2CircleShape circle;
        circle.m_radius = 26.0/PTM_RATIO;
        
        b2FixtureDef ballShapeDef;
        ballShapeDef.shape = &circle;
        ballShapeDef.density = 1.0f;
        ballShapeDef.friction = 0.2f;
        ballShapeDef.restitution = 0.8f;
        _body->CreateFixture(&ballShapeDef);
        
        [self schedule:@selector(tick:)];
        
        // Create edges around the entire screen
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(0,0);
        
        b2Body *groundBody = _world->CreateBody(&groundBodyDef);
        b2EdgeShape groundEdge;
        b2FixtureDef boxShapeDef;
        boxShapeDef.shape = &groundEdge;
        
        //wall definitions
        groundEdge.Set(b2Vec2(0,0), b2Vec2(winSize.width/PTM_RATIO, 0));
        groundBody->CreateFixture(&boxShapeDef);
        
        groundEdge.Set(b2Vec2(0,0), b2Vec2(0,winSize.height/PTM_RATIO));
        groundBody->CreateFixture(&boxShapeDef);
        
        groundEdge.Set(b2Vec2(0, winSize.height/PTM_RATIO),
                       b2Vec2(winSize.width/PTM_RATIO, winSize.height/PTM_RATIO));
        groundBody->CreateFixture(&boxShapeDef);
        
        groundEdge.Set(b2Vec2(winSize.width/PTM_RATIO, winSize.height/PTM_RATIO),
                       b2Vec2(winSize.width/PTM_RATIO, 0));
        groundBody->CreateFixture(&boxShapeDef);
        
//        self.isAccelerometerEnabled = YES;
        [self setAccelerometerEnabled:YES];
        
         [self schedule:@selector(kick) interval:5.0];        
       
    }
    return self;
}

- (void)kick {
    b2Vec2 force = b2Vec2(30, 30);
    _body->ApplyLinearImpulse(force,_body->GetPosition());
}

- (void)tick:(ccTime) dt {
    
    _world->Step(dt, 10, 10);
    for(b2Body *b = _world->GetBodyList(); b; b=b->GetNext()) {
        if (b->GetUserData() != NULL) {
            CCSprite *ballData = (CCSprite *)b->GetUserData();
            ballData.position = ccp(b->GetPosition().x * PTM_RATIO,
                                    b->GetPosition().y * PTM_RATIO);
            ballData.rotation = -1 * CC_RADIANS_TO_DEGREES(b->GetAngle());
        }
    }
}


- (void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration {
    
    // Landscape left values
    b2Vec2 gravity(acceleration.y * 30, -acceleration.x * 30);
    _world->SetGravity(gravity);
    
}

- (void)dealloc {
    delete _world;
    _body = NULL;
    _world = NULL;
    [super dealloc];
}

@end