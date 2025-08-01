//
//  ViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 4/8/19.
//  Copyright © 2019 Display.io. All rights reserved.
//
#import <AppTrackingTransparency/AppTrackingTransparency.h>

#import "ViewController.h"
#import "PlacementType.h"
#import "PlacementViewController.h"

#import <DIOSDK/DIOController.h>

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
            NSLog(@"ATT STATUS = %ld", (long)status);
        }];
    });
    
    NSString *appId = @"7522";
    
    id data = @[@{@"id": @"4788", @"type": [NSNumber numberWithInt:PlacementTypeInterstitial]}, // Video
                @{@"id": @"5426", @"type": [NSNumber numberWithInt:PlacementTypeInFeed]}, // Video
                @{@"id": @"6340", @"type": [NSNumber numberWithInt:PlacementTypeInterscrollerVideo]}, // Video
                @{@"id": @"6340", @"type": [NSNumber numberWithInt:PlacementTypeInterscrollerVideoORTB]}, // Video oRTB in CollectionView
                @{@"id": @"6299", @"type": [NSNumber numberWithInt:PlacementTypeBanner]},
                @{@"id": @"6372", @"type": [NSNumber numberWithInt:PlacementTypeMediumRectangle]},
                @{@"id": @"5427", @"type": [NSNumber numberWithInt:PlacementTypeInterstitial]}, // Html
                @{@"id": @"5362", @"type": [NSNumber numberWithInt:PlacementTypeInFeed]}, // Html
                @{@"id": @"6339", @"type": [NSNumber numberWithInt:PlacementTypeInterscrollerHtml]},// Html
                @{@"id": @"5426", @"type": [NSNumber numberWithInt:PlacementTypeInFeedSwiftUI]}, // Video
                @{@"id": @"6340", @"type": [NSNumber numberWithInt:PlacementTypeInterscrollerSwiftUI]}, // Video
];

    [[DIOController sharedInstance] initializeWithAppId:appId completionHandler:^{
        NSLog(@"CONTROLLER INITIALIZED, DIO SDK VER: %@", [[DIOController sharedInstance] getSDKVersion]);
        
        PlacementViewController *placementViewController = [PlacementViewController new];
        placementViewController.data = data;
        
        UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:placementViewController];
        navigationController.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
        navigationController.modalPresentationStyle = UIModalPresentationFullScreen;
        [self presentViewController:navigationController animated:NO completion:nil];
    } errorHandler:^(NSError *error) {
        NSLog(@"ON INIT WITH ERROR: %@", error.localizedDescription);
    }];
}

@end
