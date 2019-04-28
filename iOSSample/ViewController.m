//
//  ViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 4/8/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "ViewController.h"

#import <DIOSDK/DIOController.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [[DIOController sharedInstance] initializeWithAppId:@"6494" completionHandler:^{
        [self onInit];
    } errorHandler:^(NSString *error) {
        [self onInitWithError:error];
    }];
}

- (void)onInit {
    NSLog(@"ON INIT");
    
    DIOPlacement *placement = [[DIOController sharedInstance] placementWithId:@"3231"];
    DIOAdRequest *request = [placement newAdRequest];
    
//    [request setYearOfBirth:1975];
//    [request setGender:AD_REQUEST_MALE];
//    [request setKeywords:@[@"house of cards", @"lamborghini"]];
    
    [request requestAdWithAdReceivedHandler:^(DIOAdProvider *adProvider) {
        NSLog(@"AD RECEIVED");
        
        [adProvider loadAdWithLoadedHandler:^(DIOAd *ad) {
            NSLog(@"AD LOADED");
            
            [ad showAdFromViewController:self eventHandler:^(DIOAdEvent event){
                switch (event) {
                    case DIOAdEventOnShown:
                        NSLog(@"AdEventOnShown");
                        break;
                    case DIOAdEventOnFailedToShow:
                        NSLog(@"AdEventOnFailedToShow");
                        break;
                    case DIOAdEventOnClicked:
                        NSLog(@"AdEventOnClicked");
                        break;
                    case DIOAdEventOnClosed:
                        NSLog(@"AdEventOnClosed");
                        break;
                    case DIOAdEventOnAdCompleted:
                        NSLog(@"AdEventOnAdCompleted");
                        break;
                }
            }];
        } failedHandler:^(NSString *message){
            NSLog(@"AD FAILED TO LOAD: %@", message);
        }];
    } noAdHandler:^{
        NSLog(@"NO AD");
    }];
}

- (void)onInitWithError:(NSString*)message {
    NSLog(@"ON INIT WITH ERROR: %@", message);
}

@end
