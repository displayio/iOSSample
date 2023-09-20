//
//  DIOVideoAd.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/26/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DIOAdUnit.h"
#import "DIOVideoPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOVideoAd : DIOAdUnit

@property (nonatomic, strong) id videoData;
@property (nonatomic, strong) id videoParams;
@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) NSString *clickURL;

- (void)parseMediaFile;
- (void)triggerOmLoadedEvent;
- (void)createVideoAdSession:(DIOVideoPlayer*) videoPlayer;

@end

NS_ASSUME_NONNULL_END
