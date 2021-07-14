//
//  DIOMediumRectangle.h
//  DIOSDK
//
//  Created by Ariel Malka on 12/15/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOAdUnit.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOMediumRectangle : NSObject

+ (DIOAdUnit*)factoryWithSubtype:(NSString*)subtype requestId:(NSString*)requestId data:(id)data offering:(id)offering;

@end

NS_ASSUME_NONNULL_END
