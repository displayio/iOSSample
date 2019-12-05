//
//  StaticViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 8/27/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "StaticViewController.h"

#import <DIOSDK/DIOInFeedView.h>

@interface StaticViewController ()

@end

@implementation StaticViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStylePlain target:self action:@selector(close:)];

    self.view.backgroundColor = UIColor.whiteColor;
    self.navigationController.navigationBar.translucent = NO;
    
    //
    
    DIOInFeedView *inFeedView = (DIOInFeedView*)[self.ad view];
    
    [self.view addSubview:inFeedView];
    [inFeedView.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor].active = YES;
    [inFeedView.topAnchor constraintEqualToAnchor:self.view.topAnchor].active = YES;
    [inFeedView.widthAnchor constraintEqualToAnchor:self.view.widthAnchor].active = YES;
    [inFeedView.heightAnchor constraintEqualToConstant:[inFeedView height]].active = YES;
}

- (void)close:(id)sender {
    [self.ad finish];
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
