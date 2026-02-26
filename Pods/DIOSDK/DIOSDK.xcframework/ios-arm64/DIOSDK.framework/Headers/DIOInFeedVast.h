//
//  DIOInFeedVast.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/23/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOMediaAd.h>
#import <DIOSDK/DIOInFeedVideoPlayer.h>
#import <DIOSDK/DIOMediaPreloader.h>
#import <DIOSDK/DIOInFeedVastProtocol.h>
#import <DIOSDK/DIOInFeedView.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInFeedVast : DIOMediaAd <DIOMediaPreloaderDelegate, DIOInFeedVastProtocol>

@property (nonatomic, strong) DIOInFeedView *inFeedView;
@property (nonatomic) BOOL headlineMode;
@property (nonatomic) BOOL adLabelHide;
@property (nonatomic) BOOL ctaHide;
@property (nonatomic) BOOL advertiserHide;
@property (nonatomic, strong) NSString* adLabelText;
@end

NS_ASSUME_NONNULL_END
