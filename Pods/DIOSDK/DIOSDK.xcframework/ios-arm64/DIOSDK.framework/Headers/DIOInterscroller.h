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

+ (DIOAdUnit*)factoryWithSubtype:(NSString*)subtype requestId:(NSString*)requestId data:(id)data offering:(id)offering;

@end

NS_ASSUME_NONNULL_END
