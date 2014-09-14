//
//  BueleButton.m
//  002-TableView_todolist
//
//  Created by Raffaele Bua on 21/02/14.
//

#import "BueleButton.h"

@implementation BueleButton

- (id)initWithFrame:(CGRect)frame andLabel:(NSString *)label
{
    self = [super initWithFrame:frame];
    if (self) {
        [self setTitleColor:([UIColor whiteColor]) forState:( UIControlStateNormal )];
		[self setTitle:label forState:UIControlStateNormal];
        [self setBackgroundColor:([UIColor blackColor])];
        [self setAutoresizingMask:UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin];
    }
    
    return self;
}

@end