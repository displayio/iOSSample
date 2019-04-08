//
//  DIOPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DIOAdRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOPlacement : NSObject

@property (nonatomic, strong) NSString *ID;

/**
 @return A new ad request for this placement.
 */
- (DIOAdRequest*)newAdRequest;

- (instancetype)initWithId:(NSString*)ID;
- (void)setup:(id)data;
- (BOOL)isOperative;
- (NSString*)name;
- (BOOL)hasPendingAdRequests;
- (DIOAdRequest*)lastAdRequest;
- (DIOAdRequest*)adRequestById:(NSString*)requestId;
- (void)removeAdRequestById:(NSString*)requestId;

@end

NS_ASSUME_NONNULL_END
