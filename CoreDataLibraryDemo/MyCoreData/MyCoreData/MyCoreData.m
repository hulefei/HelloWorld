//
//  MyCoreData.m
//  MyCoreData
//
//  Created by Hanson on 13-8-11.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#import "MyCoreData.h"

@implementation MyCoreData

+ (void)hello {
    NSLog(@"hello");
}

- (void)initialize {
    // 从应用程序包中加载模型文件
    _model = [NSManagedObjectModel mergedModelFromBundles:nil];
    // 传入模型对象，初始化NSPersistentStoreCoordinator
    _psc = [[NSPersistentStoreCoordinator alloc] initWithManagedObjectModel:_model];
    // 构建SQLite数据库文件的路径
    NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
    NSURL *url = [NSURL fileURLWithPath:[docs stringByAppendingPathComponent:@"person.data"]];
    // 添加持久化存储库，这里使用SQLite作为存储库
    NSError *error = nil;
    NSPersistentStore *store = [_psc addPersistentStoreWithType:NSSQLiteStoreType configuration:nil URL:url options:nil error:&error];
    if (store == nil) { // 直接抛异常
        [NSException raise:@"添加数据库错误" format:@"%@", [error localizedDescription]];
    }
    
    // 初始化上下文，设置persistentStoreCoordinator属性
    _context = [[NSManagedObjectContext alloc] init];
    _context.persistentStoreCoordinator = _psc;
    // 用完之后，记得要[context release];
    
    NSLog(@"initialize");
}

- (void)add {
    // 传入上下文，创建一个Person实体对象
    NSManagedObject *person = [NSEntityDescription insertNewObjectForEntityForName:@"Person" inManagedObjectContext:_context];
    // 设置Person的简单属性
    [person setValue:@"MJ" forKey:@"name"];
    [person setValue:[NSNumber numberWithInt:27] forKey:@"age"];
    
    NSError *error = nil;
    BOOL success = [_context save:&error];
    if (!success) {
        [NSException raise:@"访问数据库错误" format:@"%@", [error localizedDescription]];
    }
    
    NSLog(@"add");
}
- (void)query {
    // 初始化一个查询请求
    NSFetchRequest *request = [[NSFetchRequest alloc] init];
    // 设置要查询的实体
    request.entity = [NSEntityDescription entityForName:@"Person" inManagedObjectContext:_context];
    // 执行请求
    NSError *error = nil;
    NSArray *objs = [_context executeFetchRequest:request error:&error];
    if (error) {
        [NSException raise:@"查询错误" format:@"%@", [error localizedDescription]];
    }
    // 遍历数据
    for (NSManagedObject *obj in objs) {
        NSLog(@"name=%@", [obj valueForKey:@"name"]);
    }
    
    NSLog(@"query");
}

- (void)deleteObject {
    // 初始化一个查询请求
    NSFetchRequest *request = [[NSFetchRequest alloc] init];
    // 设置要查询的实体
    request.entity = [NSEntityDescription entityForName:@"Person" inManagedObjectContext:_context];
    
    // 执行请求
    NSError *error = nil;
    NSArray *objs = [_context executeFetchRequest:request error:&error];
    
    // 传入需要删除的实体对象
    for (NSManagedObject *obj in objs) {
        [_context deleteObject:obj];
    }
    
    // 将结果同步到数据库
    [_context save:&error];
    if (error) {
        [NSException raise:@"删除错误" format:@"%@", [error localizedDescription]];
    }
    
    NSLog(@"deleteObject");
}

@end
