//
//  DIOOutstreamVideo.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/8/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import "DIOVideoAd.h"
#import "DIOOutstreamVideoVideoPlayer.h"
#import "DIOOutstreamVideoView.h"
#import "DIOVideoPreloader.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOOutstreamVideo : DIOVideoAd <DIOVideoPlayerDelegate, DIOVideoPreloaderDelegate, DIOOutstreamVideoViewDelegate>

@property (nonatomic, strong) DIOOutstreamVideoVideoPlayer *player;
@property (nonatomic, weak) DIOOutstreamVideoView *containerView;

+ (DIOAdUnit*)factoryWithSubtype:(NSString*)subtype requestId:(NSString*)requestId data:(id)data offering:(id)offering;

@end

NS_ASSUME_NONNULL_END
