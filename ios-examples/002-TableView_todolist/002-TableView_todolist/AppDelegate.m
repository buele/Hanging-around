//
//  AppDelegate.m
//  002-TableView_todolist
//
//  Created by Raffaele Bua on 18/03/14.
//  Copyright (c) 2014 Buele. All rights reserved.
//

#import "BueleButton.h"
#import "AppDelegate.h"


@implementation AppDelegate
@synthesize window;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    bueleTableView = [[BueleTableViewController alloc] init];
	[self.window addSubview:bueleTableView.view];
    [self.window makeKeyAndVisible];
    
    return YES;
}

- (void)dealloc {
	[bueleTableView release];
    [window release];
    [super dealloc];
}

@end
