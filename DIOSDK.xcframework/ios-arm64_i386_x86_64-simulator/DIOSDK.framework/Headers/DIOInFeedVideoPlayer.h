//
//  DIOInFeedVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/25/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOVideoPlayer.h"
#import "DIOPlayerView.h"
#import "DIOInFeedView.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOInFeedVideoPlayer : DIOVideoPlayer

@property (nonatomic, strong) DIOInFeedView *inFeedView;
@property (nonatomic) BOOL framed;
@property (nonatomic) BOOL detailed;

- (instancetype)initWithParams:(id)params;

- (void)activate;
- (void)deactivate;
- (void)leave;
- (void)reenter;

@end

NS_ASSUME_NONNULL_END
