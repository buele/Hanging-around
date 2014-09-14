//
//  BueleView.h
//  BueleTableView
//
//  Created by Raffaele Bua on 09/03/11.
//

#import <UIKit/UIKit.h>
#import "BueleButton.h"


extern const CGRect TITLE_RECT;
extern const CGRect TEXTVIEW_RECT;
extern const CGRect PUSH_BUTTON_RECT;
extern const CGRect EDIT_BUTTON_RECT;

@protocol BueleViewDelegate
@optional
-(void) pushButtonDidPressed:(NSString *) boeleText;
-(void) editButtonDidPressed;
@end


@interface BueleView : UIView {
	id<BueleViewDelegate>delegate;
	UITextView * bueleTextView;
    UILabel * title;
}

-(UIColor * ) colorFromR:(int)r G:(int)g B:(int)b;
-(UIColor *) getEditButtonColor;
-(UIColor *) getAddButtonColor;
-(UIColor *) getBackgroundColor;

@property(nonatomic,retain)id<BueleViewDelegate>delegate;
@property (nonatomic, retain) BueleButton * editButton;
@property (nonatomic, retain) BueleButton * pushButton;

@end
