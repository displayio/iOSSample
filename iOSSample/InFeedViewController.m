//
//  InFeedViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 4/23/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "InFeedViewController.h"
#import "CustomCell1.h"
#import "CustomCell2.h"

@interface InFeedViewController ()

@property (nonatomic, strong) NSArray<NSArray<NSNumber*>*> *ids;

@end

@implementation InFeedViewController

- (void)viewDidLoad {
    [ super viewDidLoad];
    
    [self.tableView registerClass:[CustomCell1 class] forCellReuseIdentifier:@"IDENTIFIER1"];
    [self.tableView registerClass:[CustomCell2 class] forCellReuseIdentifier:@"IDENTIFIER2"];
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"IDENTIFIER3"];
    
    self.ids = @[@[@1, @0, @1], @[@2, @0, @1], @[@0, @1, @0]];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStylePlain target:self action:@selector(close:)];
    
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    self.navigationController.navigationBar.translucent = NO;
}

- (void)close:(id)sender {
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
            UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"IDENTIFIER3" forIndexPath:indexPath];
            cell.selectionStyle = UITableViewCellSelectionStyleNone;
            
            UIView *view = [self.ad view];
            
            if (cell.contentView.subviews.count > 0) [cell.contentView.subviews[0] removeFromSuperview];
            [cell.contentView addSubview:view];
            
            [cell.contentView.leadingAnchor constraintEqualToAnchor:view.leadingAnchor].active = YES;
            [cell.contentView.trailingAnchor constraintEqualToAnchor:view.trailingAnchor].active = YES;
            [cell.contentView.topAnchor constraintEqualToAnchor:view.topAnchor].active = YES;
            [cell.contentView.bottomAnchor constraintEqualToAnchor:view.bottomAnchor].active = YES;
            
            return cell;
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
            return [[self.ad view] height];
    }
    
    return 0;
}

@end
