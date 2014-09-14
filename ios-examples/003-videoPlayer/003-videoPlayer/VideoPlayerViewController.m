//
//  VideoPlayerViewController.m
//  003-videoPlayer
//
//  Created by Raffaele Bua on 20/03/14.
//

#import "VideoPlayerViewController.h"

@interface VideoPlayerViewController ()

@end

@implementation VideoPlayerViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        [self.view setBackgroundColor:[UIColor grayColor]];
        
        // create video player
        videoUrl = [[[NSURL alloc]initWithString:@"http://content.bitsontherun.com/videos/bkaovAYt-52qL9xLP.mp4"]retain];
        player = [[[MPMoviePlayerController alloc] initWithContentURL: videoUrl]retain];
        [player prepareToPlay];
        [player.view setFrame: self.view.bounds];  // player's frame must match parent's
        [self.view addSubview: player.view];
        // ...
        [player play];
    }
    return self;
}




- (void)viewDidLoad
{
    [super viewDidLoad];
	[self.view setFrame:[[UIScreen mainScreen] bounds]];

}

-(void)dealloc
{
    [player release];
    [videoUrl release];
    [super dealloc];
}

@end
