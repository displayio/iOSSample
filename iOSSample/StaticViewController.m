//
//  StaticViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 8/27/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "StaticViewController.h"

@interface StaticViewController ()

@end

@implementation StaticViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStylePlain target:self action:@selector(close:)];

    self.view.backgroundColor = UIColor.whiteColor;
    self.navigationController.navigationBar.translucent = NO;
    
    //
    
    DIOBannerView *bannerView = [self.ad view];
    
    [self.view addSubview:bannerView];
    [bannerView.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor].active = YES;
    [bannerView.topAnchor constraintEqualToAnchor:self.view.topAnchor].active = YES;
    [bannerView.widthAnchor constraintEqualToAnchor:self.view.widthAnchor].active = YES;
    [bannerView.heightAnchor constraintEqualToConstant:[bannerView height]].active = YES;
}

- (void)close:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
