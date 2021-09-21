//
//  DIOHeadlineVideoVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/8/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import "DIOVideoPlayer.h"
#import "DIOPlayerView.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOHeadlineVideoVideoPlayer : DIOVideoPlayer

@property (nonatomic, strong) UIView *view;

- (instancetype)initWithParams:(id)params;

- (void)activate;
- (void)deactivate;
- (void)leave;
- (void)reenter;
- (void)pause;
- (void)play;
- (void)showTimer;
- (void)hideSoundButton;

@end

NS_ASSUME_NONNULL_END