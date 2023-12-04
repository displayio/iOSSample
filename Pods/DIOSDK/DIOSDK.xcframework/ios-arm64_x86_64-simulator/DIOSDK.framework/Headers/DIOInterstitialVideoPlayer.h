//
//  DIOInterstitialVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/20/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOVideoPlayer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterstitialVideoPlayer : DIOVideoPlayer

- (instancetype)initWithHostView:(UIView*)hostView params:(id)params;
- (void)startWithURL:(NSURL*)url;
- (void)didTransitionToSize:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
