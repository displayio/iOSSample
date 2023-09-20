//
//  DIOMessageLogger.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/21/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOMessageLogger : NSObject

@property (nonatomic, strong) NSDateFormatter *dateFormatter;

- (void)logWithMessage:(NSString*)message;
- (void)clear;
- (NSString*)string;

@end

NS_ASSUME_NONNULL_END
