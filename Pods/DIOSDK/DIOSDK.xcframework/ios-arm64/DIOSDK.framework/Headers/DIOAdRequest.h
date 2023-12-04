//
//  DIOAdRequest.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/24/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DIOSDK/DIOAdProvider.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DIOBannerPosition) {
    DIOBannerPositionAboveTheFold = 1,
    DIOBannerPositionBelowTheFold = 3
};

@interface DIOAdRequest : NSObject
@property (nonatomic, strong) NSString *_id_;

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
 Sets the categories list. Use IAB code format 'IAB# or IAB#-#'

 @param sectionCats A list of IAB categories for app section.
 */
- (void)setIABSectionCats:(NSArray<NSString*>*)sectionCats;
/**
 Sets the categories list. Use IAB code format 'IAB# or IAB#-#'

 @param pageCats A list of IAB categories for app page.
 */
- (void)setIABPageCats:(NSArray<NSString*>*)pageCats;
/**
*/
- (void)setBuyerId:(NSString*)buyerId;
/**
 */
- (void)setUserId:(NSString*)userId;

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
