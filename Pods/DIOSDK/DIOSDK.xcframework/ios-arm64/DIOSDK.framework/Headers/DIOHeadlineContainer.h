//
//  DIOHeadlineContainer.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/9/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <DIOSDK/DIOAdRequest.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOHeadlineContainer : NSObject

- (void)loadWithAdRequest:(DIOAdRequest*)request completionHandler:(void (^)(DIOAd*))completionHandler errorHandler:(void (^)(NSError*))errorHandler;
- (instancetype)initForORTBAd:(DIOAd*)ad  placementID: (NSString*)placementId;

- (UIView*)view;
- (void)setConstraintForIndexPath :(NSIndexPath*) index;
- (void)setConstraintForScrollView;

@end

NS_ASSUME_NONNULL_END
