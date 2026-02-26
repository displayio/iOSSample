//
//  DIORewardedVideo.h
//  DIOSDK
//
//  Created by rdorofeev on 8/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOInterstitialVast.h>

NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("RewardedVideo ad unit is deprecated. Use Interstitial instead.")
@interface DIORewardedVideo : DIOInterstitialVast

- (NSString*)rewardType;
- (int)rewardAmount;
+ (DIOAdUnit*)factoryWithMarkupType:(DIOMarkupType)markupType data:(id)data;

@end

NS_ASSUME_NONNULL_END
