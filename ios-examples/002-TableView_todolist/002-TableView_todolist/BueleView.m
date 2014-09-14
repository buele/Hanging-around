//
//  BueleView.m
//  BueleTableView
//
//  Created by Raffaele Bua on 09/03/11.
//

#import "BueleButton.h"
#import "BueleCell.h"
#import "BueleView.h"

@implementation BueleView
@synthesize delegate;
@synthesize editButton;
@synthesize pushButton;


const CGRect TITLE_RECT  = {{5,50},{200,30}};
const CGRect TEXTVIEW_RECT = {{5,100},{180,30}};
const CGRect PUSH_BUTTON_RECT = {{190,100},{50,30}};
const CGRect EDIT_BUTTON_RECT = {{245,100},{67,30}};

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        static NSString * titleText = @"TODO List";
        static NSString * addButtonLabel = @"Add";
        static NSString * editButtonLabel = @"Edit";
        
        // view style
		[self setFrame:[[UIScreen mainScreen] bounds]];
        [self setBackgroundColor:[self getBackgroundColor]];
		
        // buele title
        title = [[UILabel alloc]init];
        [title setFrame:TITLE_RECT];
        [title setText:titleText];
        [title setFont:[UIFont systemFontOfSize:36]];
        [title setTextColor: [UIColor blackColor]];
        [self addSubview:title];
        
        // text view
        bueleTextView = [[UITextView alloc]init];
        [bueleTextView setFrame:TEXTVIEW_RECT];
        [self addSubview:bueleTextView];
        
        // push button
        pushButton = [[[BueleButton alloc] initWithFrame:PUSH_BUTTON_RECT andLabel:addButtonLabel]retain];
        [pushButton setBackgroundColor:[self getAddButtonColor]];
        [pushButton addTarget:self action:@selector(pushButtonDidPressed) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:pushButton];
        
        //edit button
        self.editButton = [[[BueleButton alloc] initWithFrame:EDIT_BUTTON_RECT andLabel:editButtonLabel]retain];
        [self.editButton addTarget:self action:@selector(editButtonDidPressed) forControlEvents:UIControlEventTouchUpInside];
        [self.editButton setBackgroundColor:[self getEditButtonColor]];
		[self addSubview:self.editButton];
	}
    
    return self;
}

-(void)pushButtonDidPressed
{
    [delegate pushButtonDidPressed:bueleTextView.text];
    [bueleTextView setText:@""];
}

-(void)editButtonDidPressed
{
	[delegate editButtonDidPressed];
}


-(UIColor *) getEditButtonColor
{
    return [self colorFromR:41 G:128 B:185];
}

-(UIColor *) getAddButtonColor
{
    return [self colorFromR:22 G:160 B:133];
}

-(UIColor *) getBackgroundColor
{
    return [self colorFromR:236 G:240 B:241];
}

-(UIColor*) colorFromR:(int)r G:(int)g B:(int)b
{
    return [UIColor colorWithRed:(r/255.0) green:(g/255.0) blue:(b/255.0) alpha:1];
}


- (void)dealloc {
	[pushButton release];
    [self.editButton release];
    [title release];
    [super dealloc];
}

@end
