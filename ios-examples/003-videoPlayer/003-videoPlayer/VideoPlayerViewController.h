//
//  VideoPlayerViewController.h
//  003-videoPlayer
//
//  Created by Raffaele Bua on 20/03/14.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>

@interface VideoPlayerViewController : UIViewController
{
    MPMoviePlayerController * player;
    NSURL * videoUrl;
}

@end
