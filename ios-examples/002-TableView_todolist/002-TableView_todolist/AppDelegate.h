//
//  AppDelegate.h
//  002-TableView_todolist
//
//  Created by Raffaele Bua on 18/03/14.
//  Copyright (c) 2014 Buele. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "BueleTableViewController.h"
@interface AppDelegate : UIResponder <UIApplicationDelegate>{
    UIWindow *window;
    BueleTableViewController * bueleTableView;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@end
