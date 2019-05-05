//
//  ViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 4/8/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "ViewController.h"
#import "PlacementViewController.h"

#import <DIOSDK/DIOController.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSString *appId = @"6494";
    
    id data = @[@{@"id": @"3231", @"type": [NSNumber numberWithInt:PlacementTypeInterstitial]},
                @{@"id": @"4655", @"type": [NSNumber numberWithInt:PlacementTypeBanner]}];

    [[DIOController sharedInstance] initializeWithAppId:appId completionHandler:^{
        NSLog(@"CONTROLLER INITIALIZED");
        
        PlacementViewController *placementViewController = [PlacementViewController new];
        placementViewController.data = data;
        
        UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:placementViewController];
        navigationController.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
        [self presentViewController:navigationController animated:NO completion:nil];
    } errorHandler:^(NSString *error) {
        NSLog(@"ON INIT WITH ERROR: %@", error);
    }];
}

@end
