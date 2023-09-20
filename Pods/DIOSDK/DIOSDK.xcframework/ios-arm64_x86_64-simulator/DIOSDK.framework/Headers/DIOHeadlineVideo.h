//
//  DIOHeadlineVideo.h
//  DIOSDK
//
//  Created by Sergei Morozov on 25.01.22.
//  Copyright © 2022 Display.io. All rights reserved.
//

#import "DIOVideoAd.h"
#import "DIOHeadlineVideoPlayer.h"
#import "DIOHeadlineView.h"
#import "DIOVideoPreloader.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOHeadlineVideo : DIOVideoAd <DIOVideoPlayerDelegate, DIOVideoPreloaderDelegate, DIOHeadlineViewDelegate>

@property (nonatomic, strong) DIOHeadlineVideoPlayer *player;
@property (nonatomic, weak) DIOHeadlineView *containerView;

@end

NS_ASSUME_NONNULL_END
