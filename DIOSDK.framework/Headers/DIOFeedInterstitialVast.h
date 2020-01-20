//
//  DIOFeedInterstitialVast.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/18/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOVideoAd.h"
#import "DIOFeedInterstitialVideoPlayer.h"
#import "DIOFeedInterstitialView.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOFeedInterstitialVast : DIOVideoAd <DIOVideoPlayerDelegate, DIOFeedInterstitialViewDelegate>

@property (nonatomic, strong) DIOFeedInterstitialVideoPlayer *player;
@property (nonatomic, weak) DIOFeedInterstitialView *containerView;

@end

NS_ASSUME_NONNULL_END
