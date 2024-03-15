//
//  DIOInterscroller.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/18/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOAdUnit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscroller : NSObject

+ (DIOAdUnit*)factoryWithSubtype:(NSString*)subtype data:(id)data;

@end

NS_ASSUME_NONNULL_END
