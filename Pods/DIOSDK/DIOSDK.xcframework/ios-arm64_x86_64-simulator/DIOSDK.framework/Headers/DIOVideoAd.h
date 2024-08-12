//
//  DIOVideoAd.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/26/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DIOSDK/DIOAdUnit.h>
#import <DIOSDK/DIOVideoPlayer.h>
#import <DIOSDK/DIOEndCard.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOVideoAd : DIOAdUnit

@property (nonatomic, strong) id videoData;
@property (nonatomic, strong) id videoParams;
@property (nonatomic, strong) NSString *url;
@property (nonatomic) BOOL isStreaming;
@property (nonatomic, strong) NSString *clickURL;
@property (nonatomic) BOOL defaultMute;
@property (nonatomic, strong, nullable) DIOEndCard *endCard;
@property (nonatomic, strong) NSString* ctaText;

- (void)parseMediaFile;
- (void)triggerOmLoadedEvent;
- (void)createVideoAdSession:(DIOVideoPlayer*) videoPlayer;
- (void)replaceVideoWithEndcard;
- (BOOL)isEndcardAvailable;
- (id)getVideoEvents;

@end

NS_ASSUME_NONNULL_END
