//
//  BueleCell.h
//  BueleTableView
//
//  Created by Raffaele Bua on 14/03/14.
//
//

#import <UIKit/UIKit.h>
#import "RemoveButton.h"
@protocol BueleCellDelegate
@optional
-(void) removeItem:(NSIndexPath *) indexPath;
@end

extern const CGRect REMOVE_BUTTON_RECT;
extern const CGRect LABEL_RECT;

@interface BueleCell : UITableViewCell{
    id<BueleCellDelegate>delegate;
    UIImage * removeImage;
}

@property (nonatomic, retain) UILabel * label;
@property (nonatomic,retain) RemoveButton * removeButton;
@property (nonatomic, retain) NSIndexPath * indexPath;
@property (nonatomic,retain) id<BueleCellDelegate>delegate;

@end
