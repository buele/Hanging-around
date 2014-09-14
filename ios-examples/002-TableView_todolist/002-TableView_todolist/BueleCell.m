//
//  BueleCell.m
//  BueleTableView
//
//  Created by Raffaele Bua on 14/03/14.
//
//
#import "BueleButton.h"
#import "BueleCell.h"

@implementation BueleCell
@synthesize label;
@synthesize indexPath;
@synthesize removeButton;
@synthesize delegate;

const CGRect REMOVE_BUTTON_RECT = {{270,15},{15,15}};
const CGRect LABEL_RECT = {{10,0},{250,40}};

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        
        // delete image
        NSString *imagePath = [[NSBundle mainBundle] pathForResource:@"delete_icon" ofType:@"png"];
        removeImage = [[[UIImage alloc] initWithContentsOfFile:imagePath] retain];
        
        // set label
        label = [[[UILabel alloc] init] retain];
        [label setFrame:LABEL_RECT];
        [self addSubview:label];
       
        
        // set remove button
        self.removeButton = [[[RemoveButton alloc] init] retain];
        [removeButton setFrame:REMOVE_BUTTON_RECT];
        [removeButton setBackgroundImage:removeImage forState:UIControlStateNormal];
        [removeButton addTarget:self action:@selector(removeButtonDidPressed:) forControlEvents:UIControlEventTouchUpInside];
        removeButton.hidden=TRUE;
        [self addSubview:removeButton];
    }
    return self;
}

-(void)removeButtonDidPressed:(id)button
{
    RemoveButton * senderButton = (RemoveButton *) button;
    [delegate removeItem: senderButton.indexPath];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];
}

- (void)dealloc {
	[label release];
    [removeButton release];
    [removeImage release];
    [super dealloc];
}

@end
