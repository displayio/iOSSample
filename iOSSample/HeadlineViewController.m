//
//  OutstreamVideoViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 3/31/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import "HeadlineViewController.h"

#import <DIOSDK/DIOController.h>
#import <DIOSDK/DIOHeadlineContainer.h>
#import <DIOSDK/DIOHeadlineView.h>
#import <DIOSDK/DIOHeadlinePlacement.h>


@interface HeadlineViewController ()

@property (nonatomic, strong) DIOHeadlineContainer *container;

@property (nonatomic, strong) DIOAd *ad;

@end

@implementation HeadlineViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"IDENTIFIER"];
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"AD"];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStylePlain target:self action:@selector(close:)];
    
    self.navigationController.navigationBar.translucent = NO;
    
    //
    
    DIOPlacement *placement = [[DIOController sharedInstance] placementWithId:self.placementId];
//    ((DIOOutstreamVideoPlacement*)placement).backgroundColorSnap = UIColor.redColor;
    DIOAdRequest *request = [placement newAdRequest];
    
    self.container = [[DIOHeadlineContainer alloc] init];
    
    [self.container loadWithAdRequest:request completionHandler:^(DIOAd *ad){
        self.ad = ad;
    } errorHandler:^(NSError *error) {
        NSLog(@"%@", error);
    }];
}

- (void)close:(id)sender {
    if (self.ad) {
        [self.ad finish];
    }
    
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 40;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 20) {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"AD" forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;

        DIOHeadlineView *view = (DIOHeadlineView*)[self.container view];
        if (!view.detached) {
        if (cell.contentView.subviews.count > 0) [cell.contentView.subviews[0] removeFromSuperview];
            [cell.contentView addSubview:view];
        
            view.translatesAutoresizingMaskIntoConstraints = NO;
            [cell.contentView.leadingAnchor constraintEqualToAnchor:view.leadingAnchor].active = YES;
            [cell.contentView.trailingAnchor constraintEqualToAnchor:view.trailingAnchor].active = YES;
            [cell.contentView.topAnchor constraintEqualToAnchor:view.topAnchor].active = YES;
            [cell.contentView.bottomAnchor constraintEqualToAnchor:view.bottomAnchor].active = YES;
        }
        
        return cell;
    }
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"IDENTIFIER" forIndexPath:indexPath];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    cell.textLabel.text = [NSString stringWithFormat:@"%ld", indexPath.row];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 20) {
        return [(DIOHeadlineView*)[self.container view] height];
    }
    
    return UITableViewAutomaticDimension;
}

@end
