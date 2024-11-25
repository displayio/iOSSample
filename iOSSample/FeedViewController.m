//
//  FeedViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 4/23/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "FeedViewController.h"
#import "CustomCell1.h"
#import "CustomCell2.h"

#import <DIOSDK/DIOController.h>
#import <DIOSDK/DIOInFeedView.h>
#import <DIOSDK/DIOInFeedPlacement.h>

@interface FeedViewController ()

@property (nonatomic, strong) NSMutableArray<DIOAd*> *ads;

@end

@implementation FeedViewController

static const int AD_POSITION = 20;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"IDENTIFIER"];
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"AD"];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStylePlain target:self action:@selector(close:)];
    
    self.navigationController.navigationBar.translucent = NO;
    self.ads = [NSMutableArray new];
}

- (void)viewDidAppear:(BOOL)animated {
    DIOInFeedPlacement* interscrollerPlacement = (DIOInFeedPlacement*)[[DIOController sharedInstance] placementWithId:self.placementId];
    
    for (int i = 0; i<10; i++) {
        DIOAdRequest *request = [interscrollerPlacement newAdRequest];
        [request requestAdWithAdReceivedHandler:^(DIOAd * _Nonnull ad) {
            [self.ads addObject:ad];
        } noAdHandler:^(NSError * _Nonnull error) {
            NSLog(@"%@", error);
            
        }];
    }
    
}

- (void)close:(id)sender {
    for (DIOAd* ad in _ads) {
        if (ad) {
            [ad finish];
        }
    }
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 400;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    int index = (int)indexPath.row / AD_POSITION;
    bool isAdSlot = indexPath.row  != 0 && indexPath.row % AD_POSITION == 0 && index <= [self.ads count];
    
    if (isAdSlot) {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"AD" forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        
        UIView *view = [[self.ads objectAtIndex:index-1] view];
        view.translatesAutoresizingMaskIntoConstraints = NO;
        
        
        if (cell.contentView.subviews.count > 0) [cell.contentView.subviews[0] removeFromSuperview];
        [cell.contentView addSubview:view];
        
        [cell.contentView.leadingAnchor constraintEqualToAnchor:view.leadingAnchor].active = YES;
        [cell.contentView.trailingAnchor constraintEqualToAnchor:view.trailingAnchor].active = YES;
        [cell.contentView.topAnchor constraintEqualToAnchor:view.topAnchor].active = YES;
        [cell.contentView.bottomAnchor constraintEqualToAnchor:view.bottomAnchor].active = YES;
        
        return cell;
    }
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"IDENTIFIER" forIndexPath:indexPath];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    cell.textLabel.text = [NSString stringWithFormat:@"%ld", indexPath.row];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    int index = (int)indexPath.row / AD_POSITION;
    bool isAdSlot = indexPath.row  != 0 && indexPath.row % AD_POSITION == 0 && index <= [self.ads count];
    
    if (isAdSlot) {
        UIView *view = [[self.ads objectAtIndex:index-1] view];
        return [(DIOInFeedView*)view height];
    }
    return UITableViewAutomaticDimension;
}

@end
