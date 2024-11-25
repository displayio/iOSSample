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

@property (nonatomic, strong) NSMutableArray<DIOAd*> *ads;

@end

@implementation InterscrollerViewController
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
    DIOInterscrollerPlacement* interscrollerPlacement = (DIOInterscrollerPlacement*)[[DIOController sharedInstance] placementWithId:self.placementId];
    
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
