//
//  InterscrollerViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 1/12/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import "InterscrollerViewController.h"

#import <DIOSDK/DIOController.h>
#import <DIOSDK/DIOInterscrollerPlacement.h>

@interface InterscrollerViewController ()

@property (nonatomic, strong) DIOAd *ad;

@end

@implementation InterscrollerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"IDENTIFIER"];
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"AD"];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStylePlain target:self action:@selector(close:)];
    
    self.navigationController.navigationBar.translucent = NO;
    
}

- (void)viewDidAppear:(BOOL)animated {
    DIOInterscrollerPlacement* interscrollerPlacement = (DIOInterscrollerPlacement*)[[DIOController sharedInstance] placementWithId:self.placementId];
    DIOAdRequest *request = [interscrollerPlacement newAdRequest];
    [request requestAdWithAdReceivedHandler:^(DIOAd * _Nonnull ad) {
        self.ad = ad;
    } noAdHandler:^(NSError * _Nonnull error) {
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
        
        UIView *view = [self.ad view];
        
        if (cell.contentView.subviews.count > 0) [cell.contentView.subviews[0] removeFromSuperview];
        [cell.contentView addSubview:view];
        
        return cell;
    }
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"IDENTIFIER" forIndexPath:indexPath];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    cell.textLabel.text = [NSString stringWithFormat:@"%ld", indexPath.row];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return UITableViewAutomaticDimension;
}

@end
