//
//  DIOInFeedVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/25/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOVideoPlayer.h>
#import <DIOSDK/DIOPlayerView.h>
#import <DIOSDK/DIOInFeedView.h>

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
- (void)play;
- (void)toggleSound:(BOOL) isEnabled;

@end

NS_ASSUME_NONNULL_END
