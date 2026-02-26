//
//  DIOInFeedVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/25/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOMediaPlayer.h>
#import <DIOSDK/DIOPlayerView.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInFeedVideoPlayer : DIOMediaPlayer

- (instancetype)initWithAd:(id) ad;
- (void)showProgress;

@end

NS_ASSUME_NONNULL_END
