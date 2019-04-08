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

@property (nonatomic, strong) DIOVideoPlayer *player;

@end

NS_ASSUME_NONNULL_END
