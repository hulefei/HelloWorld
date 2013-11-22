//
//  CDViewController.h
//  CoreDataDemo
//
//  Created by Hanson on 13-8-4.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface CDViewController : UIViewController {
    NSManagedObjectModel *_model;
    NSPersistentStoreCoordinator *_psc;
    NSManagedObjectContext *_context;
}

@property (weak, nonatomic) IBOutlet UIButton *btn1;
@property (weak, nonatomic) IBOutlet UIButton *btn2;
@property (weak, nonatomic) IBOutlet UIButton *btn3;
@property (weak, nonatomic) IBOutlet UIButton *btn4;
@property (weak, nonatomic) IBOutlet UIButton *btn5;



- (IBAction)btn1Action:(id)sender;
- (IBAction)btn2Action:(id)sender;
- (IBAction)btn3Action:(id)sender;
- (IBAction)btn4Action:(id)sender;
- (IBAction)btn5Action:(id)sender;


@end
