//
//  DIOInFeedVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/25/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOMediaPlayer.h>
#import <DIOSDK/DIOPlayerView.h>
#import <DIOSDK/DIOInFeedView.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInFeedVideoPlayer : DIOMediaPlayer

@property (nonatomic, strong) DIOInFeedView *inFeedView;

- (instancetype)initWithAd:(id) ad;

- (void)activate;
- (void)deactivate;
- (void)leave;
- (void)reenter;
- (void)play;
- (void)showProgress;
- (void)toggleSound:(BOOL) isEnabled;

@end

NS_ASSUME_NONNULL_END
