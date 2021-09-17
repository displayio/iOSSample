//
//  DIOHeadlineVideo.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/8/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import "DIOVideoAd.h"
#import "DIOHeadlineVideoVideoPlayer.h"
#import "DIOHeadlineVideoView.h"
#import "DIOVideoPreloader.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOHeadlineVideo : DIOVideoAd <DIOVideoPlayerDelegate, DIOVideoPreloaderDelegate, DIOHeadlineVideoViewDelegate>

@property (nonatomic, strong) DIOHeadlineVideoVideoPlayer *player;
@property (nonatomic, weak) DIOHeadlineVideoView *containerView;

+ (DIOAdUnit*)factoryWithSubtype:(NSString*)subtype requestId:(NSString*)requestId data:(id)data offering:(id)offering;

@end

NS_ASSUME_NONNULL_END
