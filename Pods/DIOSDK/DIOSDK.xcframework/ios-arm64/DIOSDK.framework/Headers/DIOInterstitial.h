//
//  DIOInterstitial.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/25/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOAdUnit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterstitial : NSObject

+ (DIOAdUnit*)factoryWithMarkupType:(DIOMarkupType)markupType data:(id)data;

@end

NS_ASSUME_NONNULL_END
