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
        _ball = [CCSprite spriteWithFile:@"Ball.jpg" rect:CGRectMake(0, 0, 52, 52)];
        _ball.position = ccp(100, 100);
        [self addChild:_ball];
        
        //我们创建了world对象。当我们创建这个对象的时候，需要指定一个初始的重力向量。这里，我们设置y轴方向为-30，因此，所有的body都会往屏幕下面下落
        //我们还指定了一个值，用以指明对象不参与碰撞时，是否可以“休眠”。一个休眠的对象将不会花费处理时间，直到它与其实对象发生碰撞的时候才会“醒”过来
        b2Vec2 gravity = b2Vec2(0.0f, -30.0f);
        _world = new b2World(gravity);
        
        //首先创建一个body定义结构体，并且指定它应该放在左下角。
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(0,0);
        //然后，使用world对象来创建body对象。（注意，这里一定要使用world对象来创建，不能直接new，因为world对象会做一些内存管理操作。）
        b2Body *groundBody = _world->CreateBody(&groundBodyDef);
        
        b2EdgeShape groundEdge;
        b2FixtureDef boxShapeDef;
        boxShapeDef.shape = &groundEdge;
        //为屏幕的每一个边界创建一个多边形shape。这些“shape”仅仅是一些线段。注意，我们把像素转换成了“meter”。通过除以之前定义的比率来实现的。
        groundEdge.Set(b2Vec2(0,0), b2Vec2(winSize.width/PTM_RATIO, 0));
        //使用b2FixtureDef 创建b2Body 的 fixture
        groundBody->CreateFixture(&boxShapeDef);
        
        groundEdge.Set(b2Vec2(0,0), b2Vec2(0, winSize.height/PTM_RATIO));
        groundBody->CreateFixture(&boxShapeDef);
        
        groundEdge.Set(b2Vec2(0, winSize.height/PTM_RATIO),
                       b2Vec2(winSize.width/PTM_RATIO, winSize.height/PTM_RATIO));
        groundBody->CreateFixture(&boxShapeDef);
        
        groundEdge.Set(b2Vec2(winSize.width/PTM_RATIO,
                              winSize.height/PTM_RATIO), b2Vec2(winSize.width/PTM_RATIO, 0));
        groundBody->CreateFixture(&boxShapeDef);
        
        // Create ball body and shape
        b2BodyDef ballBodyDef;
        //我们指定body的类型为dynamic body。默认值是static body，那意味着那个body不能被移动也不会参与仿真。很明显，我们想让篮球参与仿真
        ballBodyDef.type = b2_dynamicBody;
        ballBodyDef.position.Set(100/PTM_RATIO, 100/PTM_RATIO);
        //设置body的user data属性为篮球精灵。你可以设置任何东西，但是，你设置成精灵会很方便，特别是当两个body碰撞的时候，你可以通过这个参数把精灵对象取出来，然后做一些逻辑处理。
        ballBodyDef.userData = _ball;
        _body = _world->CreateBody(&ballBodyDef);
        
        b2CircleShape circle;
        circle.m_radius = 26.0/PTM_RATIO;
        
        b2FixtureDef ballShapeDef;
        //这里使用了一个不同的shape类型–circle shape。
        ballShapeDef.shape = &circle;
        ballShapeDef.density = 1.0f;
        ballShapeDef.friction = 0.2f;
        ballShapeDef.restitution = 0.8f;
        _body->CreateFixture(&ballShapeDef);
        
        [self schedule:@selector(tick:)];
        
        self.isAccelerometerEnabled = YES;
    }
    return self;
}

- (void)tick:(ccTime) dt {
    //第一件事情就是调用world对象的step方法，这样它就可以进行物理仿真了。这里的两个参数分别是“速度迭代次数”和“位置迭代次数”–你应该设置他们的范围在8-10之间。（译者：这里的数字越小，精度越小，但是效率更高。数字越大，仿真越精确，但同时耗时更多。8一般是个折中，如果学过数值分析，应该知道迭代步数的具体作用）
    _world->Step(dt, 10, 10);
    //接下来，我们要使我们的精灵匹配物理仿真。因此，我们遍历world对象里面的所有body，然后看body的user data属性是否为空，如果不为空，就可以强制转换成精灵对象。接下来，就可以根据body的位置来更新精灵的位置了
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
    b2Vec2 gravity(-acceleration.y * 15, acceleration.x *15);
    _world->SetGravity(gravity);
    
}

- (void)dealloc {
    delete _world;
    _body = NULL;
    _world = NULL;
    [super dealloc];
}

@end