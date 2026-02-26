//
//  DIOInRing.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/23/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOMediaAd.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInRing : DIOMediaAd

+ (DIOAdUnit*)factoryWithMarkupType:(DIOMarkupType)markupType data:(id)data;

- (int)getMediaDuration;
- (void)play;
- (void)pause;

@end

NS_ASSUME_NONNULL_END
