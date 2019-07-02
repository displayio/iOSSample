//
//  AdViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 5/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "AdViewController.h"
#import "TableViewController.h"

#import <DIOSDK/DIOController.h>
#import <DIOSDK/DIOBannerVast.h>
#import <DIOSDK/DIOBannerHtml.h>
#import <DIOSDK/DIOBannerPlacement.h>

@interface AdViewController ()

@property (weak, nonatomic) IBOutlet UIButton *loadButton;
@property (weak, nonatomic) IBOutlet UIButton *showButton;

@property (nonatomic, strong) DIOAd *ad;

@end

@implementation AdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.showButton.enabled = NO;
}

- (IBAction)loadPressed:(id)sender {
    DIOPlacement *placement = [[DIOController sharedInstance] placementWithId:self.placementId];
    DIOAdRequest *adRequest = [placement newAdRequest];
    
    if ([placement isKindOfClass:[DIOBannerPlacement class]]) {
        ((DIOBannerPlacement*)placement).fullWidth = YES;
    }
    
    [adRequest setKeywords:@[@"house of cards", @"lamborghini"]];
    [adRequest setYearOfBirth:1975];
    [adRequest setGender:AD_REQUEST_MALE];
    
    [adRequest requestAdWithAdReceivedHandler:^(DIOAdProvider *adProvider) {
        NSLog(@"AD RECEIVED");
        
        [adProvider loadAdWithLoadedHandler:^(DIOAd *ad) {
            NSLog(@"AD LOADED");
            
            self.ad = ad;
            
            self.loadButton.enabled = NO;
            self.showButton.enabled = YES;
        } failedHandler:^(NSString *message){
            NSLog(@"AD FAILED TO LOAD: %@", message);
        }];
    } noAdHandler:^{
        NSLog(@"NO AD");
    }];
}

- (IBAction)showPressed:(id)sender {
    if ([self.ad isKindOfClass:[DIOBannerVast class]] || [self.ad isKindOfClass:[DIOBannerHtml class]]) {
        TableViewController *tableViewController = [TableViewController new];
        tableViewController.ad = self.ad;

        self.ad = nil;

        UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:tableViewController];
        navigationController.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
        [self presentViewController:navigationController animated:YES completion:nil];
    } else {
        [self.ad showAdFromViewController:self eventHandler:^(DIOAdEvent event){
            switch (event) {
                case DIOAdEventOnShown:
                    NSLog(@"AdEventOnShown");
                    break;
                    
                case DIOAdEventOnClicked:
                    NSLog(@"AdEventOnClicked");
                    break;
                    
                case DIOAdEventOnFailedToShow:
                    NSLog(@"AdEventOnFailedToShow");
                    self.ad = nil;
                    break;
                    
                case DIOAdEventOnClosed:
                    NSLog(@"AdEventOnClosed");
                    self.ad = nil;
                    break;
                    
                case DIOAdEventOnAdCompleted:
                    NSLog(@"AdEventOnAdCompleted");
                    self.ad = nil;
                    break;
            }
        }];
    }
}

@end
