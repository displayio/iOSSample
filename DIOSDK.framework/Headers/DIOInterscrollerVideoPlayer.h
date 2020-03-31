//
//  DIOInterscrollerVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/20/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOVideoPlayer.h"
#import "DIOPlayerView.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerVideoPlayer : DIOVideoPlayer

@property (nonatomic, strong) UIView *view;

- (instancetype)initWithParams:(id)params;

- (void)activate;
- (void)deactivate;
- (void)leave;
- (void)reenter;

@end

NS_ASSUME_NONNULL_END
