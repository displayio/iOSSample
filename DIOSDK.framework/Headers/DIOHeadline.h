//
//  DIOHeadline.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/8/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import "DIOVideoAd.h"
#import "DIOHeadlineVideoPlayer.h"
#import "DIOHeadlineView.h"
#import "DIOVideoPreloader.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOHeadline : DIOVideoAd <DIOVideoPlayerDelegate, DIOVideoPreloaderDelegate, DIOHeadlineViewDelegate>

@property (nonatomic, strong) DIOHeadlineVideoPlayer *player;
@property (nonatomic, weak) DIOHeadlineView *containerView;

+ (DIOAdUnit*)factoryWithSubtype:(NSString*)subtype requestId:(NSString*)requestId data:(id)data offering:(id)offering;

@end

NS_ASSUME_NONNULL_END
