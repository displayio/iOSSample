//
//  DIOInitProperties.h
//  DIOSDK
//
//  Created by Ariel Malka on 1/13/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString* const GENDER_FEMALE;
extern NSString* const GENDER_MALE;

typedef NS_ENUM(NSInteger, DIOCompliance) {
    DIOComplianceUnknown = -1,
    DIOComplianceNo = 0,
    DIOComplianceYes = 1
};

@interface DIOInitProperties : NSObject

@property (nonatomic, strong) NSMutableDictionary *data;

/**
 Sets the year of birth.
 
 @param yearOfBirth Year of birth (4 digits.)
 */
- (void)setYearOfBirth:(int)yearOfBirth;

/**
 Sets the gender.
 
 @param gender either 'AD_REQUEST_FEMALE' or 'AD_REQUEST_MALE'.
 */
- (void)setGender:(NSString*)gender;

/**
 Sets the user keywords.
 
 @param keywords A list of keywords.
 */
- (void)setKeywords:(NSArray<NSString*>*)keywords;

/**
 */
- (void)setChildCompliance:(DIOCompliance)compliance;

/**
 */
- (void)setDetailsRequired:(BOOL)detailsRequired;

- (DIOCompliance)childCompliance;

@end

NS_ASSUME_NONNULL_END
