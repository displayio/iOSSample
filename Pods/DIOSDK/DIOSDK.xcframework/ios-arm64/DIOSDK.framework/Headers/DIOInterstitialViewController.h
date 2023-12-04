//
//  DIOInterstitialViewController.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/3/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <DIOSDK/DIOAdUnit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterstitialViewController : UIViewController

@property (nonatomic, strong) NSString *placementId;
@property (nonatomic, strong) NSString *requestId;
@property (nonatomic, copy) void (^eventHandler)(DIOAdEvent);

@end

NS_ASSUME_NONNULL_END
