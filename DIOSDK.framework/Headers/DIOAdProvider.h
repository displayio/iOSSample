//
//  DIOAdProvider.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/24/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DIOAdUnit.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOAdProvider : NSObject

@property (nonatomic, strong) DIOAdUnit *ad;

/**
Loads an ad.
 
 @param loadedHandler A block object to be executed when the ad has been loaded. This block takes one argument: the ad.
 @param failedHandler A block object to be executed when loading has failed. This block takes one argument: the error message.
 */
- (void)loadAdWithLoadedHandler:(void (^)(DIOAd*))loadedHandler failedHandler:(void (^)(NSString*))failedHandler;

- (instancetype)initWithAds:(NSMutableArray<DIOAdUnit*>*)ads;

@end

NS_ASSUME_NONNULL_END
