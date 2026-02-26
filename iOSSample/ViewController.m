//
//  ViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 4/8/19.
//  Copyright © 2019 Display.io. All rights reserved.
//
//
//  ViewController.m
//  iOSSample
//

#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import "ViewController.h"
#import "PlacementType.h"
#import "PlacementViewController.h"
#import <DIOSDK/DIOController.h>

@interface ViewController ()
@property (nonatomic, strong) UIButton *buttonInit;
@property (nonatomic, strong) UIActivityIndicatorView *spinner;
@property (nonatomic, strong) UILabel *statusLabel;
@property (nonatomic, copy)   NSString *appId;
@property (nonatomic, strong) NSArray<NSDictionary *> *data;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor colorWithWhite:0.98 alpha:1.0];
    self.appId = @"7522";
    
    self.data = @[
        @{@"id": @"4788", @"type": @(PlacementTypeInterstitialVideo)},
        @{@"id": @"5426", @"type": @(PlacementTypeInFeedVideo)},
        @{@"id": @"6340", @"type": @(PlacementTypeInterscrollerVideo)},
        @{@"id": @"6340", @"type": @(PlacementTypeInterscrollerVideoORTB)},   // Video oRTB in CollectionView
        @{@"id": @"6299", @"type": @(PlacementTypeBanner)},
        @{@"id": @"6372", @"type": @(PlacementTypeMediumRectangle)},
        @{@"id": @"5427", @"type": @(PlacementTypeInterstitialHtml)},
        @{@"id": @"5362", @"type": @(PlacementTypeInFeedHtml)},
        @{@"id": @"6339", @"type": @(PlacementTypeInterscrollerHtml)},
        @{@"id": @"5426", @"type": @(PlacementTypeInFeedSwiftUI)},            // Video
        @{@"id": @"6340", @"type": @(PlacementTypeInterscrollerSwiftUI)},     // Video
    ];
    
    UIButtonConfiguration *config = [UIButtonConfiguration filledButtonConfiguration];
    config.title = @"Initialize SDK";
    config.baseBackgroundColor = [UIColor colorWithRed:0.47 green:0.46 blue:0.96 alpha:1.0];
    config.baseForegroundColor = UIColor.whiteColor;
    config.cornerStyle = UIButtonConfigurationCornerStyleCapsule;
    config.contentInsets = NSDirectionalEdgeInsetsMake(12, 24, 12, 24);
    config.titleTextAttributesTransformer = ^NSDictionary<NSAttributedStringKey,id> * (NSDictionary<NSAttributedStringKey,id> *incoming) {
        NSMutableDictionary *attrs = [incoming mutableCopy];
        attrs[NSFontAttributeName] = [UIFont boldSystemFontOfSize:18.0];
        return attrs;
    };
    self.buttonInit = [UIButton buttonWithType:UIButtonTypeSystem];
    self.buttonInit.configuration = config;
    self.buttonInit.translatesAutoresizingMaskIntoConstraints = NO;
    [self.buttonInit addTarget:self action:@selector(handleInitTap) forControlEvents:UIControlEventTouchUpInside];
    
    self.spinner = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleMedium];
    self.spinner.translatesAutoresizingMaskIntoConstraints = NO;
    self.spinner.hidesWhenStopped = YES;
    
    self.statusLabel = [[UILabel alloc] init];
    self.statusLabel.translatesAutoresizingMaskIntoConstraints = NO;
    self.statusLabel.textColor = UIColor.grayColor;
    self.statusLabel.font = [UIFont systemFontOfSize:14];
    self.statusLabel.numberOfLines = 0;
    self.statusLabel.textAlignment = NSTextAlignmentCenter;
    
    [self.view addSubview:self.buttonInit];
    [self.view addSubview:self.spinner];
    [self.view addSubview:self.statusLabel];
    
    [NSLayoutConstraint activateConstraints:@[
        [self.buttonInit.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor],
        [self.buttonInit.centerYAnchor constraintEqualToAnchor:self.view.centerYAnchor],
        [self.spinner.centerXAnchor constraintEqualToAnchor:self.buttonInit.centerXAnchor],
        [self.spinner.centerYAnchor constraintEqualToAnchor:self.buttonInit.centerYAnchor],
        [self.statusLabel.topAnchor constraintEqualToAnchor:self.buttonInit.bottomAnchor constant:12],
        [self.statusLabel.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor constant:24],
        [self.statusLabel.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor constant:-24],
    ]];
}

#pragma mark - Actions
- (void)handleInitTap {
    self.statusLabel.textColor = UIColor.grayColor;
    self.statusLabel.text = @"Initializing…";
    self.buttonInit.enabled = NO;
    self.buttonInit.alpha = 0.7;
    [self.spinner startAnimating];
    
    __weak typeof(self) weakSelf = self;
    void (^startInit)(void) = ^{
        [[DIOController sharedInstance] initializeWithAppId:weakSelf.appId completionHandler:^{
            dispatch_async(dispatch_get_main_queue(), ^{
                NSLog(@"CONTROLLER INITIALIZED, DIO SDK VER: %@", [[DIOController sharedInstance] getSDKVersion]);
                [weakSelf.spinner stopAnimating];
                weakSelf.statusLabel.text = @"Initialized ✓";
                [weakSelf routeToPlacements];
            });
        } errorHandler:^(NSError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [weakSelf.spinner stopAnimating];
                weakSelf.buttonInit.enabled = YES;
                weakSelf.buttonInit.alpha = 1.0;
                weakSelf.statusLabel.textColor = [UIColor colorWithRed:0.85 green:0.2 blue:0.2 alpha:1.0];
                weakSelf.statusLabel.text = [NSString stringWithFormat:@"Initialization failed: %@", error.localizedDescription ?: @"Unknown error"];
            });
        }];
    };
    
    if (@available(iOS 14, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(__unused ATTrackingManagerAuthorizationStatus status) {
            dispatch_async(dispatch_get_main_queue(), ^{
                startInit();
            });
        }];
    } else {
        startInit();
    }
}

- (void)routeToPlacements {
    PlacementViewController *placementVC = [PlacementViewController new];
    placementVC.data = self.data;
    
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:placementVC];
    nav.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
    nav.modalPresentationStyle = UIModalPresentationFullScreen;
    [self presentViewController:nav animated:YES completion:nil];
}

@end

