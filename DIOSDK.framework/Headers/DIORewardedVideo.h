//
//  DIORewardedVideo.h
//  DIOSDK
//
//  Created by rdorofeev on 8/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOInterstitialVast.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIORewardedVideo : DIOInterstitialVast

- (NSString*)rewardType;
- (int)rewardAmount;
+ (DIOAdUnit*)factoryWithSubtype:(NSString*)subtype requestId:(NSString*)requestId data:(id)data offering:(id)offering;

@end

NS_ASSUME_NONNULL_END
