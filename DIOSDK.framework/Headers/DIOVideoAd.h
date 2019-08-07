//
//  DIOVideoAd.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/26/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DIOAdUnit.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOVideoAd : DIOAdUnit

@property (nonatomic, strong) id videoData;
@property (nonatomic, strong) id videoParams;
@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) NSString *clickURL;
@property (nonatomic, strong) OMIDDisplayioVideoEvents *omVideoEvents;

- (void)parseMediaFile;
- (void)triggerOmLoadedEvent;
- (void)callAdLoadBeacon;

@end

NS_ASSUME_NONNULL_END
