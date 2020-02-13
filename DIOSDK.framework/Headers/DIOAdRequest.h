//
//  DIOAdRequest.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/24/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DIOAdProvider.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DIOBannerPosition) {
    DIOBannerPositionAboveTheFold = 1,
    DIOBannerPositionBelowTheFold = 3
};

@interface DIOAdRequest : NSObject

@property (nonatomic, strong) DIOAdProvider *adProvider;
@property (nonatomic, strong) NSString *placementId;

/**
 Sets the content keywords for this ad request.
 
 @param contentKeywords A list of content keywords.
 */
- (void)setContentKeywords:(NSArray<NSString*>*)contentKeywords;

/**
 Sets the A/B testing labels for this ad request.
 
 @param labels A list of labels.
 */
- (void)setLabels:(NSArray<NSString*>*)labels;

/**
 */
- (void)setPosition:(DIOBannerPosition)position;

/**
 Requests an ad from the server.
 
 This is an asynchronous operation.
 
 @param adReceivedHandler A block object to be executed when the ad has been received. This block takes one argument: the ad provider.
 @param noAdHandler A block object to be executed when there is no ad.
 */
- (void)requestAdWithAdReceivedHandler:(void (^)(DIOAdProvider*))adReceivedHandler noAdHandler:(void (^)(NSError*))noAdHandler;

- (instancetype)initWithPlacementId:(NSString*)placementId;
- (NSString*)ID;

@end

NS_ASSUME_NONNULL_END
