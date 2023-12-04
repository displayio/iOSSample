//
//  DIOInterscrollerContainer.h
//  DIOSDK
//
//  Created by Ariel Malka on 1/8/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <DIOSDK/DIOORTBRequest.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerContainer : NSObject

- (void)loadWithAdRequest:(DIOAdRequest*)request completionHandler:(void (^)(DIOAd*))completionHandler
             errorHandler:(void(^)(NSError*))errorHandler;
- (instancetype)initForORTBAd:(DIOAd*)ad  placementID: (NSString*)placementId;

- (UIView*)view;
- (int)containerHeight;

@end

NS_ASSUME_NONNULL_END
