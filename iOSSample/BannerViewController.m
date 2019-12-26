//
//  BannerViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 8/27/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "BannerViewController.h"

@interface BannerViewController ()

@end

@implementation BannerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStylePlain target:self action:@selector(close:)];

    self.view.backgroundColor = UIColor.whiteColor;
    self.navigationController.navigationBar.translucent = NO;
    
    //
    
    UIView *bannerView = [self.ad view];
    
    [self.view addSubview:bannerView];
    [bannerView.topAnchor constraintEqualToAnchor:self.view.topAnchor].active = YES;
    [bannerView.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor].active = YES;
}

- (void)close:(id)sender {
    [self.ad finish];
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
