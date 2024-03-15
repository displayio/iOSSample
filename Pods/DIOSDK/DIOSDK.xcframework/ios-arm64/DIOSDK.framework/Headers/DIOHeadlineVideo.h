//
//  DIOHeadlineVideo.h
//  DIOSDK
//
//  Created by Sergei Morozov on 25.01.22.
//  Copyright © 2022 Display.io. All rights reserved.
//

#import <DIOSDK/DIOVideoAd.h>
#import <DIOSDK/DIOHeadlineVideoPlayer.h>
#import <DIOSDK/DIOHeadlineView.h>
#import <DIOSDK/DIOVideoPreloader.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOHeadlineVideo : DIOVideoAd <DIOVideoPlayerDelegate, DIOVideoPreloaderDelegate, DIOHeadlineViewDelegate>

@property (nonatomic, strong) DIOHeadlineVideoPlayer *player;
@property (nonatomic, weak) DIOHeadlineView *containerView;
@property (nonatomic) BOOL headlineMode;
@property (nonatomic) BOOL allowSwipeOff;

@end

NS_ASSUME_NONNULL_END
