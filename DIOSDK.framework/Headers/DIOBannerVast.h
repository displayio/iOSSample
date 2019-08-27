//
//  DIOBannerVast.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/23/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DIOVideoAd.h"
#import "DIOBannerVideoPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOBannerVast : DIOVideoAd <DIOVideoPlayerDelegate, DIOBannerViewDelegate>

@property (nonatomic, strong) DIOBannerVideoPlayer *player;

@end

NS_ASSUME_NONNULL_END
