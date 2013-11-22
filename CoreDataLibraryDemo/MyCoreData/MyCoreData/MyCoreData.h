//
//  MyCoreData.h
//  MyCoreData
//
//  Created by Hanson on 13-8-11.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface MyCoreData : NSObject {
    NSManagedObjectModel *_model;
    NSPersistentStoreCoordinator *_psc;
    NSManagedObjectContext *_context;
}

+ (void)hello;
- (void)initialize;
- (void)add;
- (void)query;
- (void)deleteObject;

@end
