//
//  DIOMediumRectangle.h
//  DIOSDK
//
//  Created by Ariel Malka on 12/15/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOAdUnit.h>

NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("MediumRectangle ad unit is deprecated. Use InFeed instead.")
@interface DIOMediumRectangle : NSObject

+ (DIOAdUnit*)factoryWithMarkupType:(DIOMarkupType)markupType data:(id)data;

@end

NS_ASSUME_NONNULL_END
