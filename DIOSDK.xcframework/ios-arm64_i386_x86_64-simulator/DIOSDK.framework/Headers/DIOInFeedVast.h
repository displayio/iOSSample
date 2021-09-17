//
//  DIOInFeedVast.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/23/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOVideoAd.h"
#import "DIOInFeedVideoPlayer.h"
#import "DIOVideoPreloader.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOInFeedVast : DIOVideoAd <DIOVideoPlayerDelegate, DIOVideoPreloaderDelegate, DIOInFeedViewDelegate>

@property (nonatomic, strong) DIOInFeedVideoPlayer *player;

@end

NS_ASSUME_NONNULL_END
