//
//  BueleTableView.m
//  BueleTableView
//
//  Created by Raffaele Bua 09/03/11.
//

#import "BueleButton.h"
#import "BueleCell.h"
#import "BueleTableViewController.h"


@implementation BueleTableViewController
@synthesize bueleArray;
@synthesize bueleIndexPath;

const CGRect BUELE_VIEW_RECT = {{0,0},{307,150}};
const CGRect TABLE_VIEW_RECT = {{5,150},{307,300}};

- (id)init{
    self = [super init];
    if (self) {
        
        // init status
        self.bueleIndexPath = NULL;
        [self setEditing:NO];
        bueleArray = [[NSMutableArray alloc] init];
        
        // buele view
		bueleView = [[BueleView alloc]initWithFrame:BUELE_VIEW_RECT];
        [bueleView setDelegate:self];
        [self.view addSubview:bueleView];
		
        // table view
        bueleTable =[[UITableView alloc] initWithFrame: TABLE_VIEW_RECT style:UITableViewStyleGrouped];
		[bueleTable setDelegate:self];
		[bueleTable setDataSource:self];
        [self.view addSubview:bueleTable];
    }
	
    return self;
}



-(void) removeItem:(NSIndexPath *) indexPath
{
    [bueleArray removeObjectAtIndex: indexPath.row];
    [bueleTable reloadData];
    self.bueleIndexPath = NULL;
}

-(void)editButtonDidPressed
{
    static NSString * CANCEL = @"Cancel";
    static NSString * EDIT = @"Edit";

    [self setEditing:![self isEditing]];
    [bueleView.editButton setTitle:(self.editing)?CANCEL:EDIT forState:UIControlStateNormal];
    [bueleView.editButton setBackgroundColor:(self.editing)?[UIColor grayColor]:[bueleView getEditButtonColor]];
    [bueleTable reloadData];
    
}

-(void)pushButtonDidPressed:(NSString * ) boeleText
{
    if ([boeleText length] > 0) {
        [bueleArray insertObject:boeleText atIndex:[bueleArray count]];
        [bueleTable reloadData];
        [self.view endEditing:YES];
    }
}

- (void)loadView
{
	[super loadView];
	[bueleTable setDataSource:self];
	[bueleTable reloadData];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return YES;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}

- (void)dealloc {	
	[bueleIndexPath release];
	[bueleTable release];
	[bueleArray release];
	[bueleView release];
    [super dealloc];
}


#pragma mark TableView protocol

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
	self.bueleIndexPath = indexPath;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [bueleArray count];
}

- (BueleCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString * cellIdentifier = @"Cell";
    BueleCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    if (cell == nil)
        cell = [[[BueleCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier] autorelease];
	[cell.label setText:[bueleArray objectAtIndex:indexPath.row]];
    [cell setIndexPath:indexPath];
    [cell.removeButton setIndexPath:indexPath];
    cell.removeButton.hidden=![self isEditing];
    cell.delegate = (id)self;
    
    return cell;
}

@end
