//
//  DIOInFeedVast.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/23/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DIOVideoAd.h"
#import "DIOInFeedVideoPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOInFeedVast : DIOVideoAd <DIOVideoPlayerDelegate, DIOInFeedViewDelegate>

@property (nonatomic, strong) DIOInFeedVideoPlayer *player;

@end

NS_ASSUME_NONNULL_END
