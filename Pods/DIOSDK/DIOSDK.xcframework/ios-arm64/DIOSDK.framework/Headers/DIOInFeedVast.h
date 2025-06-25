//
//  DIOInFeedVast.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/23/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOVideoAd.h>
#import <DIOSDK/DIOInFeedVideoPlayer.h>
#import <DIOSDK/DIOMediaPreloader.h>
#import <DIOSDK/DIOInFeedVastProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInFeedVast : DIOVideoAd <DIOMediaPlayerDelegate, DIOMediaPreloaderDelegate, DIOInFeedViewDelegate, DIOInFeedVastProtocol>

@property (nonatomic, strong) DIOInFeedVideoPlayer *player;
@property (nonatomic) bool headlineMode;
@property (nonatomic) bool adLabelHide;
@property (nonatomic) bool ctaHide;
@property (nonatomic) bool advertiserHide;
@property (nonatomic, strong) NSString* adLabelText;
@end

NS_ASSUME_NONNULL_END
