//
//  TableViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 4/23/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "TableViewController.h"
#import "CustomCell1.h"
#import "CustomCell2.h"

#import <DIOSDK/DIOTableAdapter.h>

@interface TableViewController ()

@property (nonatomic, strong) DIOTableAdapter *adapter;
@property (nonatomic, strong) NSArray<NSArray<NSNumber*>*> *ids;

@end

@implementation TableViewController

- (void)viewDidLoad {
    [ super viewDidLoad];
    
    [self.tableView registerClass:[CustomCell1 class] forCellReuseIdentifier:@"IDENTIFIER1"];
    [self.tableView registerClass:[CustomCell2 class] forCellReuseIdentifier:@"IDENTIFIER2"];
    
    self.adapter = [[DIOTableAdapter alloc] initWithTableView:self.tableView];
    [self.adapter setAd:self.ad forIndexPath:[NSIndexPath indexPathForRow:0 inSection:1]];
    
    self.ids = @[@[@1, @0, @1], @[@2, @0, @1], @[@0, @1, @0]];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStylePlain target:self action:@selector(close:)];
    
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
}

- (void)close:(id)sender {
    [self.ad finish];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return [self.ids count];
}

- (nullable NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    switch (section) {
        case 0:
            return @"SECTION 1";
        case 1:
            return @"SECTION 2";
        case 2:
            return @"SECTION 3";
    }
    
    return nil;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.ids[section] count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    switch ([self.ids[indexPath.section][indexPath.row] intValue])
    {
        case 0:
        {
            return [tableView dequeueReusableCellWithIdentifier:@"IDENTIFIER1" forIndexPath:indexPath];
        }
            
        case 1:
        {
            return [tableView dequeueReusableCellWithIdentifier:@"IDENTIFIER2" forIndexPath:indexPath];
        }
            
        case 2:
        {
            return [self.adapter dequeueReusableCellForIndexPath:indexPath fullWidth:NO];
        }
    }
    
    return nil;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    switch ([self.ids[indexPath.section][indexPath.row] intValue])
    {
        case 0:
            return 150;
            
        case 1:
            return 100;
            
        case 2:
            return [self.adapter heightForRowAtIndexPath:indexPath];
    }
    
    return 0;
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    [self.adapter tableViewDidScroll];
}

@end
