//
//  Person.h
//  CoreDataDemo
//
//  Created by Hanson on 13-8-5.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Card;

@interface Person : NSManagedObject

@property (nonatomic, retain) NSNumber * age;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) Card *card;

@end
