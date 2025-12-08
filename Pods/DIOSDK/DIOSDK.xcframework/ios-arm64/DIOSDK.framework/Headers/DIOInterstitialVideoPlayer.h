//
//  DIOInterstitialVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/20/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOMediaPlayer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterstitialVideoPlayer : DIOMediaPlayer

- (instancetype)initWithHostView:(UIView*)hostView withAd:(id)ad;
- (void)startWithURL:(NSURL*)url;
- (void)resume;
- (void)pause;
- (void)didTransitionToSize:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
