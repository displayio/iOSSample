//
//  FeedInterstitialViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 1/12/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import "FeedInterstitialViewController.h"

#import <DIOSDK/DIOController.h>
#import <DIOSDK/DIOFeedInterstitialContainer.h>

@interface FeedInterstitialViewController ()

@property (nonatomic, strong) DIOFeedInterstitialContainer *container;

@property (nonatomic, strong) DIOAd *ad;

@end

@implementation FeedInterstitialViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"IDENTIFIER"];
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"AD"];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStylePlain target:self action:@selector(close:)];
    
    self.navigationController.navigationBar.translucent = NO;
    
    //
    
    DIOPlacement *placement = [[DIOController sharedInstance] placementWithId:self.placementId];
    DIOAdRequest *request = [placement newAdRequest];
    
    self.container = [[DIOFeedInterstitialContainer alloc] init];
    
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

        UIView *view = [self.container view];
        
        if (cell.contentView.subviews.count > 0) [cell.contentView.subviews[0] removeFromSuperview];
        [cell.contentView addSubview:view];
        
        view.translatesAutoresizingMaskIntoConstraints = NO;
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
    if (indexPath.row == 20) {
        return self.tableView.frame.size.height;
    }
    
    return UITableViewAutomaticDimension;
}

@end