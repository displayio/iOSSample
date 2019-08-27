//
//  DIOBannerVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/25/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOVideoPlayer.h"
#import "DIOPlayerView.h"
#import "DIOBannerView.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOBannerVideoPlayer : DIOVideoPlayer

@property (nonatomic, strong) DIOBannerView *bannerView;
@property (nonatomic) BOOL framed;
@property (nonatomic) BOOL detailed;

- (instancetype)initWithURL:(NSURL*)url params:(id)params;

- (void)activate;
- (void)deactivate;

@end

NS_ASSUME_NONNULL_END
