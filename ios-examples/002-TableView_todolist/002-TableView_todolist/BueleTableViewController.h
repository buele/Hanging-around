//
//  BueleTableView.h
//  BueleTableView
//
//  Created by Raffaele Bua on 09/03/11.
//

#import <UIKit/UIKit.h>
#import "BueleView.h"

extern const CGRect BUELE_VIEW_RECT;
extern const CGRect TABLE_VIEW_RECT;

@interface BueleTableViewController : UIViewController  <UITableViewDelegate,UITableViewDataSource,BueleViewDelegate>
 {
	BueleView * bueleView;
	UITableView * bueleTable;
	NSMutableArray * bueleArray;
    
 }

-(void) pushButtonDidPressed:(NSString * ) bueleText;
-(void) editButtonDidPressed;
-(void) removeItem:(NSIndexPath *) indexPath;

@property (nonatomic, retain) NSArray * bueleArray;
@property (nonatomic, retain) NSIndexPath * bueleIndexPath;
@property (nonatomic, assign, getter=isEditing) BOOL editing;


@end
