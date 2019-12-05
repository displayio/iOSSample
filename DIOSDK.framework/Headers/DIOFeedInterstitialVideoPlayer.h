//
//  DIOFeedInterstitialVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/20/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOVideoPlayer.h"
#import "DIOPlayerView.h"
#import "DIOFeedInterstitialView.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOFeedInterstitialVideoPlayer : DIOVideoPlayer

@property (nonatomic, strong) DIOFeedInterstitialView *feedInterstitialView;

- (instancetype)initWithURL:(NSURL*)url params:(id)params viewParams:(id)viewParams;

- (void)activate;
- (void)deactivate;
- (void)leave;
- (void)reenter;

@end

NS_ASSUME_NONNULL_END
