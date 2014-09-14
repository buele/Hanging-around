//
//  AppDelegate.m
//  003-videoPlayer
//
//  Created by Raffaele Bua on 20/03/14.
//

#import "VideoPlayerViewController.h"
#import "AppDelegate.h"


@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    videoPlayerViewController = [[VideoPlayerViewController alloc]init];
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    [self.window makeKeyAndVisible];
    [self.window addSubview:videoPlayerViewController.view];
    return YES;
}

-(void)dealloc
{
    [VideoPlayerViewController release];
    [super dealloc];
}


@end
