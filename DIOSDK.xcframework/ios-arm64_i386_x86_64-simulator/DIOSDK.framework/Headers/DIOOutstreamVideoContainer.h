//
//  DIOOutstreamVideoContainer.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/9/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import "DIOAdRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOOutstreamVideoContainer : NSObject

- (void)loadWithAdRequest:(DIOAdRequest*)request completionHandler:(void (^)(DIOAd*))completionHandler errorHandler:(void (^)(NSError*))errorHandler;
- (UIView*)view;

@end

NS_ASSUME_NONNULL_END
