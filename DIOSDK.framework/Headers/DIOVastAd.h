//
//  DIOVastAd.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/26/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DIOVideoAd.h"
#import "DIOInterstitialVideoPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOVastAd : DIOVideoAd

@property (nonatomic, strong) DIOInterstitialVideoPlayer *player;

- (void)renderAdComponentsWithHostView:(UIView*)hostView;
- (void)playFromWeb;

@end

NS_ASSUME_NONNULL_END
