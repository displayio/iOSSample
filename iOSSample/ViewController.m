//
//  ViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 4/8/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "ViewController.h"
#import "PlacementType.h"
#import "PlacementViewController.h"

#import <DIOSDK/DIOController.h>

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSString *appId = @"7522";
    
    id data = @[@{@"id": @"4788", @"type": [NSNumber numberWithInt:PlacementTypeInterstitial]}, // Video
                @{@"id": @"5426", @"type": [NSNumber numberWithInt:PlacementTypeInFeed]}, // Video
                @{@"id": @"6340", @"type": [NSNumber numberWithInt:PlacementTypeFeedInterstitial]}, // Video
                @{@"id": @"6299", @"type": [NSNumber numberWithInt:PlacementTypeBanner]},
                @{@"id": @"6372", @"type": [NSNumber numberWithInt:PlacementTypeMediumRectangle]},
                @{@"id": @"5427", @"type": [NSNumber numberWithInt:PlacementTypeInterstitial]}, // Html
                @{@"id": @"5362", @"type": [NSNumber numberWithInt:PlacementTypeInFeed]}, // Html
                @{@"id": @"6339", @"type": [NSNumber numberWithInt:PlacementTypeFeedInterstitial]}]; // Html

    DIOInitProperties *properties = [[DIOInitProperties alloc] init];
    [properties setGender:GENDER_MALE];
    [properties setYearOfBirth:1980];
    
    [[DIOController sharedInstance] initializeWithProperties:properties appId:appId completionHandler:^{
        NSLog(@"CONTROLLER INITIALIZED");
        
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
