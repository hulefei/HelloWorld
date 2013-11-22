//
//  Card.h
//  CoreDataDemo
//
//  Created by Hanson on 13-8-5.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Card : NSManagedObject

@property (nonatomic, retain) NSString * no;
@property (nonatomic, retain) NSManagedObject *person;

@end
