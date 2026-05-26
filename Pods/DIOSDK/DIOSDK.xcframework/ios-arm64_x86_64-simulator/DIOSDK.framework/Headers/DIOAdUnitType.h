//
//  DIOAdUnitType.h
//  DIOSDK
//
//  Created by Ro Do on 23.01.2024.
//  Copyright © 2024 Display.io. All rights reserved.
//

#define DIOAdUnitType_h

#import <Foundation/Foundation.h>

static NSString* const INTERSTITIAL = @"interstitial";
static NSString* const INFEED = @"infeed";
static NSString* const REWARDEDVIDEO DEPRECATED_MSG_ATTRIBUTE("RewardedVideo is deprecated. Use Interstitial instead.") = @"rewardedvideo";
static NSString* const INTERSCROLLER = @"interscroller";
static NSString* const BANNER = @"banner";
static NSString* const MEDIUMRECTANGLE DEPRECATED_MSG_ATTRIBUTE("MediumRectangle is deprecated. Use InFeed instead.") = @"mediumrectangle";
static NSString* const INRING = @"inring";
static NSString* const INFLOWAUDIO = @"inflowaudio";
static NSString* const INLINE = @"inline";
static NSString* const NATIVE = @"native";

typedef NS_ENUM(NSInteger, DIOMarkupType) {
    DIOMarkupTypeUnknown = 0,
    DIOMarkupTypeBanner  = 1,
    DIOMarkupTypeVideo   = 2,
    DIOMarkupTypeAudio   = 3,
    DIOMarkupTypeNative  = 4
};

static inline DIOMarkupType DIOMarkupTypeFromValue(NSInteger value) {
    switch (value) {
        case 1: return DIOMarkupTypeBanner;
        case 2: return DIOMarkupTypeVideo;
        case 3: return DIOMarkupTypeAudio;
        case 4: return DIOMarkupTypeNative;
        default: return DIOMarkupTypeUnknown;
    }
}

