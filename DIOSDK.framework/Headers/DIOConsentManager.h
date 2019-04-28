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

@interface DIOConsentManager : NSObject

- (NSString*)consentString;
- (SubjectToGDPR)subjectToGDPR;
- (BOOL)cmpPresent;
- (NSString*)parsedVendorConsents;
- (NSString*)parsedPurposeConsents;
- (id)iabConsentProperties;

@end

NS_ASSUME_NONNULL_END
