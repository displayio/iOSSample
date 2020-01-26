//
//  DIOConsentManager.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/19/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CMPDataStorageUserDefaults.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DIOConsentState) {
    DIOConsentStateYES,
    DIOConsentStateNO,
    DIOConsentStateUNKNOWN
};
#define consentTypeArray @"YES", @"NO", @"UNKNOWN", nil

@interface DIOConsentManager : NSObject

- (NSString*)consentString;
- (SubjectToGDPR)subjectToGDPR;
- (BOOL)cmpPresent;
- (NSString*)parsedVendorConsents;
- (NSString*)parsedPurposeConsents;
- (id)iabConsentProperties;
- (void)clearIABConsentData;
- (id)сonsentData;
- (void)setConsentData:(DIOConsentState) consentState gdprState:(DIOConsentState) gdprState;
- (NSString*) consentStateEnumToString:(DIOConsentState)state;
- (DIOConsentState)consentState;
- (DIOConsentState)gdprState;

@end

NS_ASSUME_NONNULL_END
