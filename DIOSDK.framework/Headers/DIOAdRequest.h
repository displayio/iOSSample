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

extern NSString* const AD_REQUEST_FEMALE;
extern NSString* const AD_REQUEST_MALE;

@interface DIOAdRequest : NSObject

@property (nonatomic, strong) DIOAdProvider *adProvider;
@property (nonatomic, strong) NSString *placementId;

/**
 Sets the year of birth for this ad request.
 
 @param yearOfBirth Year of birth (4 digits.)
 */
- (void)setYearOfBirth:(int)yearOfBirth;

/**
 Sets the gender for this ad request.
 
 @param gender either 'AD_REQUEST_FEMALE' or 'AD_REQUEST_MALE'.
 */
- (void)setGender:(NSString*)gender;

/**
 Sets the keywords for this ad request.
 
 @param keywords A list of keywords.
 */
- (void)setKeywords:(NSArray<NSString*>*)keywords;

/**
 Sets the content keywords for this ad request. Not sensitive to GDPR.
 
 @param contentKeywords A list of contentKeywords.
 */
- (void)setContentKeywords:(NSArray<NSString*>*)contentKeywords;

- (void)setDetailsRequired:(BOOL)detailsRequired;

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
