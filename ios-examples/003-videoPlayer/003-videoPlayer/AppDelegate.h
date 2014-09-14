//
//  AppDelegate.h
//  003-videoPlayer
//
//  Created by Raffaele Bua on 20/03/14.
//

#import <UIKit/UIKit.h>
#import "VideoPlayerViewController.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>
{
    VideoPlayerViewController * videoPlayerViewController;
}

@property (strong, nonatomic) UIWindow *window;

@end
