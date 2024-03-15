//
//  DIOHeadline.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/8/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <DIOSDK/DIOAdUnit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOHeadline : NSObject

+ (DIOAdUnit*)factoryWithSubtype:(NSString*)subtype data:(id)data;

@end

NS_ASSUME_NONNULL_END
